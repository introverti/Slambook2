#include<iostream>
#include<cmath>
using namespace std;

#include<Eigen/Core>
#include<Eigen/Geometry>

using namespace Eigen;

int main(int argc, char** argv)
{
    //3D matrix rotation
    Matrix3d rotation_matrix=Matrix3d::Identity();
    
    //vectory rotation AngleAxisd
    AngleAxisd rotation_vectory(M_PI/4,Vector3d(0,0,1));
    
    cout.precision(3);
    //use matrix() to transforme to matrix format
    cout<<"rotation matrix =\n"<<rotation_vectory.matrix()<<endl;
    rotation_matrix=rotation_vectory.toRotationMatrix();
    
    //use AngleAxisd to switch coordinary
    Vector3d v(1,0,0);
    Vector3d v_rotated=rotation_vectory*v;
    cout<<"(1,0,0) after rotation (by angle axis) = "<< v_rotated.transpose()<<endl;
    
    //use Matrix
    v_rotated=rotation_matrix*v;
    cout<<"(1,0,0) after rotation (by matrix) = "<<v_rotated.transpose()<<endl;
    
    //Euler
    //ZYX, roll,pitch,yaw
    Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0);
    cout<<"yaw pitch roll = "<<euler_angles.transpose()<<endl;
    
    //Euler transforme matrix by Eigen::Isometry
    Isometry3d T=Isometry3d::Identity();//3d,in face it is 4*4
    T.rotate(rotation_vectory);
    T.pretranslate(Vector3d(1,3,4));
    cout<<"Transforme matrix = \n" <<T.matrix()<<endl;
    
    //use transforme matrix to switch coordinary
    Vector3d v_transformed =T*v; //equal to R*v+t
    cout<<"v transformed = "<< v_transformed.transpose()<<endl;
    
    //Eigen::Affine3d and EIgen::Projective3d for more transformation
    
    //Quaternion
    Quaterniond q =Quaterniond(rotation_vectory);
    cout<<"quaternion form rotation vector = "<<q.coeffs().transpose()<<endl;
    //coeffs(x,y,z,w), w is the real part; x,y,z are imagiaire
    
    q=Quaterniond(rotation_matrix);
    cout<<"quaternion from rotation matrix = "<<q.coeffs().transpose()<<endl;
    
    //
    v_rotated=q*v; // actually qvq^{-1}
    cout<<"(1,0,0) after rotation ="<<v_rotated.transpose()<<endl;
    
    cout<<"should be equal to "<< (q*Quaterniond(0,1,0,0)*q.inverse()).coeffs().transpose()<<endl;
    
    return 0;
}
