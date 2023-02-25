#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>

using namespace std;

auto main() -> int {

    /** Create and Initialze the vector */
    vector<int> nums;
    for(int i=0; i< 10; i++) {
        nums.push_back(i);
    }

    /** Display the vector */
    cout<<"\nPrinting Elements of Vector num \n";
    copy(
        begin(nums),
        end(nums),
        ostream_iterator<int>(cout, " ")
    );

    // Declaring the vector containing primes
    vector<int> primes;

    copy_if(
        begin(nums),
        end(nums),
        back_inserter(primes),
        [](int x) {
            if(x < 2) {
                return (x != 0) ? true : false;
            } else {
                for(int i=2; i< x; i++) {
                    if(x % i == 0)
                        return false;
                }
                return true;
            }
        }
    );

    // Declaring the vector containing primes
    vector<int> nonPrimes;

    remove_copy_if(
        begin(nums),
        end(nums),
        back_inserter(nonPrimes),
        [](int x) {
            if(x < 2) {
                return (x != 0) ? true : false;
            } else {
                for(int i=2; i< x; i++) {
                    if(x % i == 0)
                        return false;
                }
                return true;
            }
        }
    );

    // Printing prime numbers
    /** Display the vector */
    cout<<"\nPrinting elements of prime numebrs \n";
    copy(
        begin(primes),
        end(primes),
        ostream_iterator<int>(cout, " ")
    );

    // Printing prime numbers
    /** Display the vector */
    cout<<"\nPrinting elements of Non Prime numebrs \n";
    copy(
        begin(nonPrimes),
        end(nonPrimes),
        ostream_iterator<int>(cout, " ")
    );
}
