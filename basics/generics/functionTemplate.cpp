#include <iostream>

using namespace std;

/**
 * Function template return max
 *
 * @tparam T
 * @param first
 * @param second
 * @return
 */
template <typename T>
T templateMax(T first, T second) {
    return first > second ? first : second;
}

/***
 * Main takes two input from standard input and returns the max from standard output.
 * For types that do not support > or < (logical operator), do operation overloading on that data types.
 *
 * @param argc
 * @param argv
 * @return
 */
auto main(int argc, char *argv[]) -> int {
    int a, b;
    cout<<"Enter variable a and b: ";
    cin>>a>>b;
    cout<<"Max element is: "<<templateMax<int>(a, b)<<endl;
    return 0;
}
