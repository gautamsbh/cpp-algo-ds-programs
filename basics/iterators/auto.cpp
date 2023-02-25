#include<iostream>
#include<typeinfo>

using namespace std;

const int func1();
const int& func2();
int i =2;

struct X { double d; };
const X* x = new X();

/**
* Deltype will help to find the retrn type..
* Deltype(func1()) f1
*/
auto add(int i, int j) -> int {
  return i + j;
}


/**
* RTTI (Run Time Type Information). This feature is enable by GCC by default.
* This helps to find the type of the variables at Run Time and Compile Time.
*
*/
int main(int argc, char *argv[]) {
    cout<<"These are the types declared by auto : "<<endl;

    auto a = 1;
    auto b = 1.5;
    auto c = a+ b;
    auto d = {b, c};

    cout<<"The type of A is : "<< typeid(a).name()<<endl;
    cout<<"The type of B is : "<< typeid(b).name()<<endl;
    cout<<"The type of C is :"<< typeid(c).name()<<endl;
    cout<<"The type of D is :"<< typeid(d).name()<<endl;

    cout<<"The Summation is : "<<add(2,4)<<endl;

    cout<<"Program Finished \n";
}
