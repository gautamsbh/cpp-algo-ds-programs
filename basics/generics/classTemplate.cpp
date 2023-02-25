#include <iostream>

using namespace std;

template<class T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(const T arr[], int size);

    void print();
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

template<class T>
Array<T>::Array(const T *arr, int size_arg) {
    ptr = new T[size];
    size = size_arg;
    for (int i = 0; i < size; i++) {
        ptr[i] = arr[i];
    }
}

/**
 * Invoke the template method
 *
 * @param argc
 * @param argv
 * @return
 */
auto main(int argc, char *argv[]) -> int {
    int arr[] = {1, 2, 3, 4, 5};
    Array<int> arInstance(arr, sizeof(arr) / sizeof(arr[0]));
    arInstance.print();
    return 0;
}
