#include<iostream>
#include<functional>
#include<typeinfo>
#include<vector>

using namespace std;

// Define the function as Data Type
// Defining FuncType will accept two int
// And return int datatype
typedef function<int(int, int)> FuncType;

int addition(int x, int y) {
  return x + y;
}

int subtraction(int x, int y) {
  return x - y;
}

int multiplication(int x, int y) {
  return x * y;
}

int division(int x, int y) {
  return x/y;
}

// Function called
void functionPass(FuncType fn, int x, int y) {
    cout<<"Out of the called functon is : "<<fn(x,y)<<endl;
}

auto main() -> int {
    cout << "Enter the option to perform operations " << '\n';
    int i, a, b;
    vector<FuncType> functions;

    functions.push_back(addition);
    functions.push_back(subtraction);
    functions.push_back(multiplication);
    functions.push_back(division);


    // Displaying choice to select to perform operations
    cout<<"1 for Addition : "<<endl;
    cout<<"2 for subtraction : "<<endl;
    cout<<"3 for multiplication : "<<endl;
    cout<<"4 for division : "<<endl;

    cout<<"Enter your choice : ";
    cin>>i;

    if(i < 1 || i > 4 ) {
        cout<<"Sorry you have choosen wrong options: "<<endl;
        return 1;
    }

    cout<<"Enter value for a -> ";
    cin>>a;

    // Input validation for variable a
    while(cin.fail()) {
        // clearing the input buffer. to restore cin to a usable state
        cin.clear();
        // Ignoring the last Input
        cin.ignore(INT_MAX, '\n');

        cout<<"Enter the integer value for variable a -> ";
        cin>>a;
    }

    cout<<"Enter value for b -> ";
    cin>>b;
    // Input validation for variable a
    while(cin.fail()) {
        // clearing the input buffer. to restore cin to a usable state
        cin.clear();
        // Ignoring the last Input
        cin.ignore(INT_MAX, '\n');

        cout<<"Enter the integer value for variable a -> ";
        cin>>b;
    }

    cout<<"Output is : "<<functions.at(i -1)(a, b)<<endl;

    return 0;
}
