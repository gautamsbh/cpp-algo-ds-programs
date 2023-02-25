#include<iostream>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Create a Set of Two Integers
    // Remember it is Ordered set
    // And Sets Properties it always contains unique information
    // And Contains Sorted Data
    set<string> opt;
    string word="";
    do
    {
        cout<<"Enter word To Enter : \t ";
        cin>>word;
        opt.insert(word);
    }while(word!="quit");
    // Now Store All Words to Set And its time to Print
    // Those Unique values and Create a Set iterator
    set<string>::iterator it=opt.begin();
    while(it!=opt.end())
    {
        cout<<*it<<endl;
        it++;
    }
    return 0;
}
