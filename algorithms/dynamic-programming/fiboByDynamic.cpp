#include<iostream>
#include<cmath>
#include<typeinfo>

using namespace std;

auto main() -> int {

    cout<<"Enter the number to get Fibonacci : ";
    int fib;
    cin>>fib;

    // You need to store the last result
    int fibos[fib];
    fibos[0] = fibos[1] = 1;
    for(int i=2;i<fib;i++) {
        fibos[i] = fibos[i-1] + fibos[i-2];
    }

    cout<<"The result is : "<<fibos[fib-1];
    return 0;
}
