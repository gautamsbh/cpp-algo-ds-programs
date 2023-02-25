#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> arr = {9,8,7,6,5,4,2,4,7}; // Initialization list
    // now sort the array
    sort(arr.begin(), arr.end());
    // print the array
    for (int data : arr)
        cout<<data<<" ";
    cout<<"\n";
    sort(arr.rbegin(), arr.rend());
     // print the array
    for (int data : arr)
        cout<<data<<" ";
    cout<<"\n";

    return 0;
}
