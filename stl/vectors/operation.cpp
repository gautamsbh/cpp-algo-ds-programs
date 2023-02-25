#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>

using namespace std;

bool comparer(int a, int b) {
  return (a> b);
}

auto main() -> int {
  // Store the collection in vector for re-sizeable Store
  cout<<"Store Elements array : "<<endl;
  vector<int> vec = {1,2,3,4,5};

  // Add a new Elment un vector
  vec.push_back(6);

  // Modifying the Elements
  vec.at(0) = 10;
  vec.at(1) = 11;

  // Sort the vector using alogirthm
  sort(vec.begin(), vec.end());

  // Display the Elements
  for(auto elem : vec) {
    cout<<elem<<" ";
  }
  cout<<"\nProgram Finished"<<endl;
}
