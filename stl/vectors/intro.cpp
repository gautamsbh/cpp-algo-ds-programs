#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec; // If you want initally some capacity in vector then pass it to Constructor
    for(int i=0;i<100;i++)
    {
        vec.push_back(i);
    }
    // Find Sum OF these Numbers within vector
    int sum=0;
    for(int i=0;i<vec.size();i++)
    {
        sum+=vec.at(i); // You can have used [] operator for values referncing
    }
    cout<<"Sum of Elements "<<sum<<endl;
    // Now Accoumulate the Vector
    // Print front and back elments
    // Print size & capacity
    cout<<"Size is : "<<vec.size()<<endl<<"Capacity : "<<vec.capacity()<<endl;
    return 0;
}
