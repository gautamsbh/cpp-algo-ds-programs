#include <iostream>
#include <vector>

using namespace std;

/**
 * Swap two elements
 * @tparam T
 * @param a
 * @param b
 */
template<typename T>
void swapTemplate(T* a, T* b) {
    T temp;
    temp = *a; *a = *b; *b = temp;
}

/**
 * Sort the array using bubble sort algorithm and return
 * @tparam T
 */
template<typename T>
void bubbleSortTemplate(vector<T>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n -1; j > i; j--) {
            if (arr[j -1] > arr[j])
                swapTemplate<int>(&arr[j - 1], &arr[j]);
        }
    }
}

/**
 * Print an array of elements
 * @param T
 */
template <typename T>
void printArrayTemplate(vector<T>& arr) {
    for (T i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

/**
 * Take number of elements to sort.
 * Enter element.
 *
 * @param argc
 * @param argv
 * @return
 */
auto main(int argc, char *argv[]) -> int {
    int n, temp;
    cout << "Enter number of elements to sort: ";
    cin >> n;

    vector<int> arr;
    cout <<"Enter space separated element: ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    bubbleSortTemplate<int>(arr, n);
    printArrayTemplate<int>(arr);
    return 0;
}
