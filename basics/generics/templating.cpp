#include<iostream>
#include<thread>

using namespace std;

template <int N>
struct Factorial {
  static const int value = N * Factorial<N-1>::value;
};
template<>
struct Factorial<0> {
  static const int value = 1;
};

// Need to pass a static value, exprssion going to evaluate at compile time
int user_function() {
  return Factorial<5>::value;  // known at compile time
}

// Driver function
int main(int argc, char *argv[]) {
  cout<<user_function()<<endl;
  return 0;
}
