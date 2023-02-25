#include<iostream>
#include<typeinfo>

using namespace std;

int main(int argc, char *argv[]) {
  cout<<"Store elements in array : "<<endl;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout<<"Iterating over the array using indexing"<<endl;

  for(int i=0; i< sizeof(arr)/ sizeof(arr[0]); i++) {
    cout<<arr[i]<<" ";
  }

  cout<<"\nIterating over the array using begin and end"<<endl;
  for(auto i = begin(arr); i != end(arr); i++) {
    cout<<*i<<" ";
  }

  cout<<"\nUsing the foreach looping structure.."<<endl;
  for(auto i : arr) {
    cout<<i<<" ";
  }

  cout<<"\nProgram Finished"<<endl;
}
