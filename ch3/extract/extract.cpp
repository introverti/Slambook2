#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(){
	Matrix4d matrix_44=Matrix4d::Random();
	cout<<"Original Matrix:\n"<<matrix_44<<endl;
	Matrix3d matrix_33=matrix_44.block(0,0,3,3);
	cout<<"left top 3x3 sousMatrix :\n"<<matrix_33<<endl;

	return 0;
}
