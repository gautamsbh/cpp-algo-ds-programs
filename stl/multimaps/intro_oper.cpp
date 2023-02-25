// There are Some problem with sets & maps
// They can only contain Unique keys
// Thus to store and operate on duplicate keys uses multi-sets & multi-maps
// But remember every key-value [pair should be unique
#include<iostream>
#include<map>
#include<utility>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multimap<string,string> dup;
    // Insert values through pair in utility header
    dup.insert(pair<string,string>("Gaurav","SAP Consultant"));
    dup.insert(pair<string,string>("Shivam","software Engineer"));
    dup.insert(pair<string,string>("Gautam","System Administrator"));
    dup.insert(pair<string,string>("Souham","Java Developer"));
    dup.insert(pair<string,string>("Gaurav","Team Leader"));
    // Search for Value
    string s="Gaurav";
    // Create an iterator of this class
    // Finding all keys with different values
    // Use Simple Iterator to store all indexes
    multimap<string,string>::iterator fin=dup.find(s);
    // Find Upper Bound
    multimap<string,string>::iterator upper_b=dup.upper_bound(s);
    // Find all Lower Bounds
    // How print all keys as we have find and upper bound pointers
    for(;fin!=upper_b;fin++)
    {
        cout<<fin->first<<" : "<<fin->second<<endl;
    }
    cout<<"\n\nAll Values Realted to Keys were Printed\n"<<endl;
    // This Iterator does not mean anything as it returns iterator bellow this key
    multimap<string,string>::iterator lower_b=dup.lower_bound(s);
    /// multimap<string,string>::iterator it=dup.beginI();
    // But here i am using auto keyword for implicit casting
    for(auto i=dup.begin();i!=dup.end();i++)
    {
        cout<<i->first<<" : "<<i->second<<endl;
    }
    return 0;
}
