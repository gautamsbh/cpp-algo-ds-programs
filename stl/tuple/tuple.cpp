#include<iostream>
#include<typeinfo>
#include<algorithm>
#include<memory>
#include<string>
#include<tuple>

using namespace std;

auto main() -> int {

  cout<<"Tuple usage "<<endl;

  tuple<int, bool, string> t1(123, true, "Hello World");

  auto t2 = make_tuple(345, false, "Contruct World");

  // Displaying the tuples using get<x>(y) template function
  cout<<"Acccessing tuple1 instance : "<<endl;
  cout<<"Integer i = "<<get<0>(t1)<<endl;
  cout<<"Boolean b = "<<get<1>(t1)<<endl;
  cout<<"String s = "<<get<2>(t1)<<endl;


  // Displaying the tuples using get<x>(y) template function
  cout<<"Acccessing tuple2 instance : "<<endl;
  cout<<"Integer i = "<<get<0>(t2)<<endl;
  cout<<"Boolean b = "<<get<1>(t2)<<endl;
  cout<<"String s = "<<get<2>(t2)<<endl;

  // Using tie and ignore to unpack the tuple
  int i;
  bool b;
  string s;

  tie(i,b,s) = t1;

  cout<<"Tie value without using ignore : "<<endl;
  cout<<"Inter i variable = "<<i<<endl;
  cout<<"Bool b variable  = "<<b<<endl;
  cout<<"String s variable = "<<s<<endl;

  tie(ignore, ignore, s) = t2;

  cout<<"Tie value without using ignore : "<<endl;
  cout<<"Inter i variable = "<<i<<endl;
  cout<<"Bool b variable  = "<<b<<endl;
  cout<<"String s variable = "<<s<<endl;


  return 0;
}
