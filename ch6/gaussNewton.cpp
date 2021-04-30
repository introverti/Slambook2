#include<iostream>
#include<opencv2/opencv.hpp>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<fstream>

using namespace std;
using namespace Eigen;

int main (int argc, char **argv){
	//真实参数值
	double ar =1.0, br =2.0, cr =1.0;
	//估计参数值 estimaiton
	double ae =2.0, be =-1.0, ce =5.0;

	int N=100;
	//噪音 noise
	double w_sigma = 1.0;
	double inv_sigma = 1.0/w_sigma;
	
	//生成随机数
	cv::RNG rng;

	//打开一个txt记录数值
	//fstream ifs;
	//ifs.open("data.txt",ios::out);

	//生成100个点的data
	vector<double> x_data,y_data;
	for (int i =0; i<N; i++){
		double x = i/100.0;
		x_data.push_back(x);
		double y =exp(ar*x*x+br*x+cr)+rng.gaussian(w_sigma*w_sigma);
		y_data.push_back(y);

		//setprecision 设置有效数字位数
		//ifs<<setprecision(10)<<x<<","<<setprecision(10)<<y<<endl;

	}
	//ifs.close();

	//Gauss-Newton 迭代
	int iterations = 100;//迭代次数

	double cost=0,lastCost=0;

	chrono::steady_clock::time_point t1=chrono::steady_clock::now();
	for (int iter=0; iter <iterations; iter++){
		
		//Gauss-Newton Hessian 被近似认为是 J^T W^{-1} J
		Matrix3d H = Matrix3d::Zero();
		//bias
		Vector3d b = Vector3d::Zero();

		cost=0;

		for (int i=0; i<N; i++){
			double xi=x_data[i], yi=y_data[i];
			double error= yi-exp(ae*xi*xi+be*xi+ce);

			Vector3d J;//雅各比矩阵
			J[0]=-xi*xi*exp(ae*xi*xi+be*xi+ce);// de/da
			J[1]=-xi*exp(ae*xi*xi+be*xi+ce);// de/db
			J[2]=-exp(ae*xi*xi+be*xi+ce);// de/dc

			H +=inv_sigma*inv_sigma*J*J.transpose();
			b +=-inv_sigma*inv_sigma*error*J;

			cost+=error *error;
		}

		//求解Hx=b
		Vector3d dx=H.ldlt().solve(b);
		if (isnan(dx[0])){
			cout<<"result is nan"<<endl;
			break;
		}

		if (iter>0 && cost>=lastCost){
			cout<<"cost:"<<cost<<">=last cost:"<<lastCost<<",break."<<endl;

		}

		ae+=dx[0];
		be+=dx[1];
		ce+=dx[2];

		lastCost=cost;
		cout<<"total cost:"<<cost<<",\t\tupdate :"<<dx.transpose()<<"\t\testimated params:"<<ae<<","<<be<<","<<ce<<endl;

	}

	chrono::steady_clock::time_point t2=chrono::steady_clock::now();

	chrono::duration<double> time_used= chrono::duration_cast<chrono::duration<double>>(t2-t1);
	cout<<"solve time_cost ="<<time_used.count()<<"seconde."<<endl;
	cout<<"estimated abc="<<ae<<","<<be<<","<<ce<<endl;
	return 0;

}




