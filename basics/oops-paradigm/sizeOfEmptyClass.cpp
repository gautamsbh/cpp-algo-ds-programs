#include<iostream>
#include<thread>
#include<cstdlib>

using namespace std;

// Create empty class and inherit then
class Empty {};
class Derived1 : public Empty {};
class Derived2 : virtual public Empty {};
class  Derived3 : public Empty {
  int a;
};
class Derived4 : virtual public Empty {
  int b;
};
class Plan {
  int a;
};
// Driver function, empty base optimization is done by compiler
int main(int argc, char *argv[]) {
  cout<<"size of Empty Class : "<<sizeof(Empty)<<endl;
  cout<<"size of Derived1 Class : "<<sizeof(Derived1)<<endl;
  cout<<"size of Derived2 Class : "<<sizeof(Derived2)<<endl;
  cout<<"size of Derived3 Class : "<<sizeof(Derived3)<<endl;
  cout<<"size of Derived4 Class : "<<sizeof(Derived4)<<endl;
  cout<<"size of Plan Class : "<<sizeof(Plan)<<endl;

  return 0;
}
