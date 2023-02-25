#include<iostream>
#include<typeinfo>

using namespace std;

/**
 * nullptr is a NULL pointer is not a macro like NULL.
 * 
 */
template<typename I, typename J>
auto add(I i, J j) -> decltype(i+j) {
  return i + j;
}
int main(int argc, char *argv[]) {
  cout<<"Templating alternative for Return types"<<endl;
  cout<<add(2, 4.5)<<endl;
  /** Template delaration and initialization */
  auto d = add<int, double>(2, 4.5);
  cout<<"Output is : "<<d<<endl;
  cout<<"Program Finished";

  return 0;
}
