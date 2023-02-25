#include<iostream>
#include<typeinfo>

using namespace std;

float circleArea(float a) {
    return 3.14 * a * a;
}
auto main() -> int {
    // Call a ciclrArea function 5 times with same input
    float radius = 2.5f;

    for(int i =0; i<5; i++) {
        cout<<"Function called : "<<circleArea(radius)<<endl;
    }

    return 0;
}
