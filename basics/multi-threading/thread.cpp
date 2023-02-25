#include<iostream>
#include<thread>

using namespace std;

// Create a function
void factorial(int n) {
    // Calculate factorial
    int result =1;
    for(int i =n; i>0; i--) {
      cout<<"Calculating factorial of "<<i<<endl;
      result = result * n;
    }
}

// Define a class and overload () operator
class OpLoad {
public:
    void operator()(int n) {
      for(int i=0;i<n;i++)
          cout<<"OpLoad class is executing"<<endl;
    }
};
// Driver function
int main(int argc, char *argv[]) {
  // Initialize the object
  thread th1(factorial, 10);
  thread th2(OpLoad(), 10);
  auto f = [](int n) {
    for(int i=0;i<n;i++)
      cout<<"Lambda Expression is evaluate for count "<<i<<endl;
    };
  thread th3(f, 10);

  // Check all the thread are completed and return
  th1.join();
  th2.join();
  th3.join();

  return 0;
}
