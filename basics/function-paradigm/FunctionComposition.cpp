#include<iostream>
#include<functional>
#include<vector>
#include<cmath>
#include<algorithm>

using std::cout;
using std::vector;
using std::function;
using std::transform;
using std::back_inserter;
using std::transform;
using std::endl;

// Defining a function that takes hyperbolic function
// One user defined function.
typedef function<double(double)> HyperbolicFunc;

// Hyberbolic functions
vector<HyperbolicFunc> funcs = {
    sinh,
    cosh,
    tanh,
    [](double x) {
        return x*x;
    }
};

// Inverse Hyperbolic functions
vector<HyperbolicFunc> inverseFuncs = {
    asinh,
    acosh,
    atanh,
    [](double x) {
        return exp(log(x)/2);
    }
};

// Declaring a template to be over used
template<typename A, typename B, typename C>
function<C(A)> compose(
    function<C(B)> f,
    function<B(A)> g ) {
        return [f, g] (A x) {
            return f(g(x));
        };
    }

auto main() -> int {
    cout<<"Function Composition "<<endl;
    vector<HyperbolicFunc> composedFuncs;

    // Initialiuze an array containing maiy double
    vector<double> nums;
    for(int i=0; i<5; i++) {
        nums.push_back(i * 0.2);
    }

    // Transform the elements inside the vector
    transform(
        begin(inverseFuncs),
        end(inverseFuncs),
        begin(funcs),
        back_inserter(composedFuncs),
        compose<double, double, double>
    );

    for(auto num : nums) {
        for(auto func: composedFuncs) {
            cout<<"f(g("<<num<<")) = "<<func(num)<<endl;
            cout<<"-----------------------------------";
        }
    }
    return 0;
}
