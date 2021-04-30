#include <iostream>
#include <fstream>
#include <string>
#include "yaml-cpp/yaml.h"
 
using namespace std;

//重载>>
template<typename T>
void operator >> (const YAML::Node& node, T& i){
  i = node.as<T>();
}


void configure(const YAML::Node& node);
void nodePrint(const YAML::Node& node);
 
int main(){
	//loadFile
  YAML::Node config = YAML::LoadFile("test.yaml");
 
  configure(config["subscribers"]);
 
  return 0;
}
 
void configure(const YAML::Node& node){
  for (unsigned int i = 0; i < node.size(); i++)
  {
    nodePrint(node[i]);
  }
}


//打印
void nodePrint(const YAML::Node& node){
  string name;
  string topic;
  double timeout;
  unsigned int priority;
 
  node["name"]       >> name;
  node["topic"]      >> topic;
  node["timeout"]    >> timeout;
  node["priority"]   >> priority;
 
  cout<<"    name: "<<name<<endl;
  cout<<"   topic: "<<topic<<endl;
  cout<<" timeout: "<<timeout<<" seconds."<<endl;
  cout<<"priority: "<<priority<<endl;
}
