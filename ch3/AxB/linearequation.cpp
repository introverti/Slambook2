#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>
#include <cmath>
#include <ctime>
#include <complex>


using namespace std;
using namespace Eigen;

//下面这两个宏的数值一样的时候 方法1 4 5 6才能正常工作
#define MATRIX_SIZE 3   //方程组个数 行
#define MATRIX_SIZE_ 3  //变量个数 列
typedef  Eigen::Matrix<double,MATRIX_SIZE, MATRIX_SIZE_>  Mat_A;
typedef  Eigen::Matrix<double ,MATRIX_SIZE,1 >              Mat_B;

//Jacobi 迭代求和
double Jacobi_sum(Mat_A &A,Mat_B &x_k,int i);

//Jacobi 迭代求解
Mat_B Jacobi(Mat_A &A,Mat_B &b,int &iteration,double &accuracy);

int main(int argc, char **argv){
	//设置cout输出精度
	cout.precision(3);

	//例子矩阵 A
	Matrix3d matrix=Matrix3d::Zero();
	matrix<< 2,-1,0,-1,2,-1,0,-1,2;
	Vector3d v=Vector3d::Zero();
	v<<1,2,3;

	//1 直接使用inverse()求逆矩阵
	//矩阵的必须可逆 rank(A)=rank(x)
	cout<<"Methode inverse()\n"<<matrix.inverse()*v<<endl;
	cout<<"********************************"<<endl;

	//2 QR分解 有解出真解，无解出近似解
	cout<<"Methode QR \n"<<matrix.colPivHouseholderQr().solve(v)<<endl;
	cout<<"********************************"<<endl;

	//3 最小二乘法
	cout<<"Methode LS\n"<<(matrix.transpose()*matrix).inverse()*(matrix.transpose()*v)<<endl;
	cout<<"********************************"<<endl;

	//4 LU分解 只适用于方阵
	cout<<"Methode LU \n"<<matrix.lu().solve(v)<<endl;
	cout<<"********************************"<<endl;

	//5 Cholesky分解 方阵
	cout<<"Methode Cholesky \n"<<matrix.llt().solve(v)<<endl;
	cout<<"********************************"<<endl;

	//6 Jacobi
	int iteration=10;
	double accuracy=0.01;
	auto x=Jacobi(matrix,v,iteration,accuracy);
	cout<<"Methode Jacpbi \n"<<x<<endl;
	cout<<"********************************"<<endl;


	
	return 0;
}

//Jacobi 迭代求解
Mat_B Jacobi(Mat_A &A,Mat_B &b,int &iteration,double &accuracy){
	Mat_B origin=MatrixXd::Zero(MATRIX_SIZE_,1);//迭代初始值
	Mat_B x_k;//迭代之后的值
	int k,i;//迭代循环次数
	double temp;//迭代变化单一维度的模值
	double R=0;//迭代变化模单一维度的最大值
	int isFlag=0;//是否满足精度的标志位

	//判断Jacobi是否收敛
	Mat_A D=MatrixXd::Zero(MATRIX_SIZE,MATRIX_SIZE_);//对角线
	Mat_A LU;//右上角和左下角三角阵的和乘上系数-1
	Mat_A temp2=A;
	Mat_A B;//迭代矩阵

	MatrixXcd EV;//特征值
	double maxEV=0.0; //最大模特征值
	int flag=0;//是否收敛的标志位
    
    
	//分解输入矩阵
	for(int l=0 ;l < MATRIX_SIZE_;l++){
        	D(l,l) = A(l,l);
        	temp2(l,l) = 0;
    	}
    	LU=-temp2;
    	B=D.inverse()*(LU);

	//求取特征值
	Eigen::EigenSolver<Mat_A> es(B);
	EV= es.eigenvalues();

	//选取模长最大的特征值作为谱半径
	for (int index =0; index<MATRIX_SIZE;index++){
		maxEV=(maxEV>__complex_abs(EV(index)))?maxEV:(__complex_abs(EV(index)));
	}

	//谱半径大于1 迭代无法收敛
	if(maxEV>=1){
		cout<<"Jacobi迭代算法结果不收敛"<<endl;
		flag=1;
	}

	if(flag==0){
		for (k=0;k<iteration;k++){
			for (i=0;i<MATRIX_SIZE_;i++){

				x_k(i)=x_k(i)+(b(i)-Jacobi_sum(A,origin,i))/A(i,i);

				temp = fabs(x_k(i)-origin(i));//float absolute

				if (fabs(x_k(i)-origin(i))>R) R=temp;
					
			}

			if (R<accuracy){
				isFlag=1;
				break;
			}

			R=0;
			origin=x_k;
		}

		if (isFlag) return x_k;
	}
	return origin;

}

//Jacobi迭代法的一步求和计算
double Jacobi_sum(Mat_A  &A,Mat_B &x_k,int i) {
     double sum;
     for(int j = 0; j< MATRIX_SIZE_;j++){
         sum += A(i,j)*x_k(j);
     }
     return sum;
}

