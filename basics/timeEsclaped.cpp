#include<iostream>
#include<chrono>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
using namespace std::chrono;

// Driver function to start and return execution status
int main(int argc, char *argv[]) {
  vector<int> arr(1000);
  auto f = []() -> int { return rand() % 1000; };
  generate(arr.begin(), arr.end(), f);

  auto start = high_resolution_clock::now();
  // not calcuate time used for sorting vector using STL sort method
  sort(arr.begin(), arr.end());
  // stop timepoint and cast the duration in microseconds
  auto stop = high_resolution_clock::now();
  duration<float> fsec = stop - start;
  auto duration = duration_cast<milliseconds>(fsec);
  cout<<"\nTime consumed by sorting method is "<<fsec.count()<<" seconds"<<endl;
  return 0;

}
