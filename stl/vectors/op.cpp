#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> store;
    store[4].push_back(1);
    store[3].push_back(2);
    store[2].push_back(3);
    store[1].push_back(4);
    for(int i=1;i<=store.size();i++)
    {
        cout<<store[i]<<"  ";
    }
}
