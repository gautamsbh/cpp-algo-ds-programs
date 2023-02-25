#include<iostream>
#include<typeinfo>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Initializing the vector and create a lambda function
 * And executing those function when required.
 *
 */
auto main(int argc, char *argv[]) -> int {

  vector<int> vect = {1,2,3,4,5};

  auto a = 10;

  auto myLambda = [&x = a]() { x += 2; };

  // Now you use this lambda expression anywhere as myLambda()
  // You can also capture list and parameter list as well.
  myLambda();

  // Displaying the new variable
  cout<<"Modified value of a = "<<a<<endl;

  // Print the element of vector using the vector notations
  // its similar to php closure or anonymous function
  // function (argument list) use (capture list) { body of function }
  // Using STL for_each loop to iteracte over collection
  // You can pass the function to find_if, for_each
  for_each(vect.begin(), vect.end(), [](auto item) { cout<< "Iterator : "<<item<<endl; } );

  // print all even numbers using the lambda expression.
  find_if(vect.begin(), vect.end(), [](auto item) { return item % 2 == 0; } );
  find_if_not(vect.begin(), vect.end(), [](auto item) { return item % 2 == 0; } );

  // Use transform() function to transform a vector and store the elements
  // by applying the filter on the basis of the condition.
  vector<int> clone;
  // Resizing the vector to the size of vect
  clone.resize(vect.size());

  // FindMax lambda function generic
  auto findMax = [](auto i, auto j) {
    return i > j ? i : j;
  }
  // Call them as findMax(12, 34);
  // Tranform the vector

  return 0;
}
