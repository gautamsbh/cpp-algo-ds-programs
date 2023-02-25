#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<numeric>
#include<array>
using namespace std;
int main()
{
    array<int,10> sam={10,2,9,4,5,6,7,8,0,1};
    // Sum Up all Elements of  Array
    cout<<accumulate(sam.begin(),sam.end(),0)<<endl;
    // Transform an Array
    cout<<"Transformation Begins Here"<<endl;
    transform(sam.begin(),sam.end(),sam.begin(),negate<int>());
    for(auto ps=sam.begin();ps!=sam.end();ps++)
    {
        cout<<*ps<<endl;
    }
    // Sort an Array
    cout<<"Sorted Array"<<endl;
    sort(sam.begin(),sam.end());
    for(auto ps=sam.begin();ps!=sam.end();ps++)
    {
        cout<<*ps<<endl;
    }
    return 0;
}
