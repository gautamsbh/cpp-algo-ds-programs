#include <iostream>

using namespace std;

/**
 * static property i, which is copied in each function template of type (int, double) at compile time.
 * @tparam T
 * @param x
 */
template <typename T>
void fun(const T& x) {
    static int i = 10;
    cout<< ++i;
    return;
}

template <typename T>
class Test {
private:
    T val;
public:
    static int count;
    Test() {
        count++;
    }
};

template <typename T>
int Test<T>::count = 0;


auto main(int argc, char *argv[]) -> int {
    fun<int>(1);
    cout<<endl;
    fun<int>(2);
    cout<<endl;
    fun<double>(1.1);
    cout<<endl;

    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout<<Test<int>::count<<" "<<Test<double>::count<<endl;
    return 0;
}
