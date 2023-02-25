#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

auto main() -> int {

    /** Create and assign value to vector v1 */
    vector<int> v1;
    for(int i=0; i<5; i++) {
        v1.push_back(i);
    }
    /** Create another vector of same size */
    vector<int> v2;
    v2.resize(v1.size());

    //transform the vector v2 by a function
    transform(
    begin(v1),
    end(v1),
    begin(v2),
    [](int x) {
        return x*x;
    }
    );

    cout<<"\nVector 1 print starts\n";
    // Print both the vector
    for(auto num: v1) {
        cout<<"\nElement : "<<num;
    }
    cout<<"\nVector 2 Print starts\n";
    // Print both the vector
    for(auto num: v2) {
        cout<<"\nElement : "<<num;
    }

    return 0;
}
