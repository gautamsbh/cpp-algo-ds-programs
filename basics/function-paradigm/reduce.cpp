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

    // Store the left fold
    int foldl = accumulate(
        begin(nums),
        end(nums),
        0,
        plus<int>() // You can pass a user defined function here
    );

    // Store the right fold
    int foldr = accumulate(
        rbegin(nums),
        rend(nums),
        0,
        plus<int>() // You can pass a user defined function here

    );
    // Output both the vallues
    cout<<"\n\nLeft Fold Output: "<<foldl<<endl;
    cout<<"\n\nRight Fild Output: "<<foldr<<endl;

}
