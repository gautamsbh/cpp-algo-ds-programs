//
// Created by adren on 9/15/2017.
//

#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

int divideNumber(int numerator,  int denominator) {
    if(denominator == 0) {
        throw std::exception();
    }

    return (numerator/denominator);
}

int exec() {
    cout<<"Enter Numerator and Denominator";
    int num, den;
    cin>>num>>den;
    try {
        cout<<divideNumber(num,den);
    }
    catch(exception exception) {
        cout<<"An Exception has occurred";
    }
    return 0;
}

char* mysteryFunction(const char *myString) {

    return const_cast<char *>(myString);
}