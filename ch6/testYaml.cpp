#include <iostream>
#include <fstream>
#include <string>
#include "yaml-cpp/yaml.h"

using namespace std;
int main(){
	YAML::Node config=YAML::LoadFile("output.yaml");
	ofstream fin("output.yaml",ios::out);
	YAML::Node node;
	node["point"];
	for (int i=0;i<10;i++){
		node["point"][i]["x_data"]=2*i;
		node["point"][i]["y_data"]=3*i;	
	}
	fin<<node<<endl;
	fin.close();
}

