#include<iostream>
#include<map>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,int> alnum; int sum=0;
    alnum["Souham"]=90;
    alnum["Shivam"]=89;
    alnum["Gaurav"]=87;
    alnum.insert(pair<string,int>("Manjari",92));
    // Print Values and map size
 ///   cout<<"Souham Marks : "<<alnum["souham"]<<"\nsize is "<<alnum.size()<<endl;
    // Now find values
    string s; cin>>s;
    // If key is not found in map then map_name.end() is returned
    // Find function in class map is used to map key-value
    if(alnum.find(s) != alnum.end())
    {
        // Remember Key is case sensitive
        cout<<"Marks of "<<s<<" : "<<alnum[s]<<endl;
    }
    else
    {
        cout<<"Marks of Given Key is not found"<<endl;
    }
    // Now print all values of maps
    // Create an iterator
    /// maps<string,int>::iterator it=alnum.begin();
    for(auto i=alnum.begin();i!=alnum.end();i++)
    {
        // Remember the Storage of maps are in sorted Sequence
        // The Iterator values are stored with help of pair
        cout<<i->first<<" : "<<i->second<<endl;
        sum+=i->second;
    }
    double average=0.0;
    // Find Average marks of students
    average=(float)sum/alnum.size(); // We have to implicit cast to float as int/int -> int only
    cout<<"Average is "<<average<<endl;
    return 0;
}
