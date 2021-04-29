#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv){
	Matrix3d R =AngleAxisd (M_PI/2,Vector3d(0,0,1)).toRotationMatrix();
	Quaterniond q(R);
	Sophus::SO3d SO3_R(R);//通过旋转矩阵构造李群SO3
	Sophus::SO3d SO3_q(q);//通过四元数构造李群SO3

	cout<<"SO(3) from matrix:\n"<<SO3_R.matrix()<<endl;
	cout<<"SO(3) from quaternion:\n"<<SO3_q.matrix()<<endl;

	//通过对数映射获取李代数
	Vector3d so3=SO3_R.log();
	cout<<"so3="<<so3.transpose()<<endl;

	//hat把向量转换成反对称矩阵 即^
	cout<<"so3 hat =\n"<<Sophus::SO3d::hat(so3)<<endl;

	//vee把反对称矩阵转化为向量
	cout<<"so3 hat vee= "<<Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose()<<endl;

	//添加扰动模型
	Vector3d update_so3(1e-4,0,0);//设定一个较小的更新量作为deltaR
	Sophus::SO3d SO3_updated=Sophus::SO3d::exp(update_so3)*SO3_R;
	cout<<"SO3 updated= \n"<<SO3_updated.matrix()<<endl;

	cout<<"************************************************************"<<endl;

	//SE(3)
	Vector3d t(1,0,0); //t X轴上的平移
	Sophus::SE3d SE3_Rt(R,t);//R+t->SE(3)
	Sophus::SE3d SE3_qt(q,t);//q+t->SE(3)
	cout<<"SE3 from R,t=\n"<<SE3_Rt.matrix()<<endl;
	cout<<"SE3 from q,t=\n"<<SE3_qt.matrix()<<endl;

	typedef Eigen::Matrix<double,6,1> Vector6d;
	Vector6d se3 = SE3_Rt.log();
	cout<<"se3 = "<<se3.transpose()<<endl;

	cout<<"se3 hat = \n"<<Sophus::SE3d::hat(se3)<<endl;
	cout<<"se3 hat vee = "<<Sophus::SE3d::vee(Sophus::SE3d::hat(se3)).transpose()<<endl;

	Vector6d update_se3;
	update_se3.setZero();
	update_se3(0,0)=1e-4d;
	Sophus::SE3d SE3_updated=Sophus::SE3d::exp(update_se3)*SE3_Rt;
	cout<<"SE3 updated="<<endl<<SE3_updated.matrix()<<endl;

	return 0;

}
