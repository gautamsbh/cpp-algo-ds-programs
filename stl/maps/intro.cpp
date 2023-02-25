// Maps is used as a Associative Array
// Remember that associative array key should be unique
// IrRespective of value.
// Its a key-value pair data data structure
#include<iostream>
#include<map>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,string> assoc;
    assoc["alpha"]="1";
    assoc["beta"]="2";
    assoc.insert(pair<string,string>("gamma","3"));
    cout<<"Output of Map"<<endl;
    cout<<assoc["beta"]<<endl;
    // Find size of Map use size function
    cout<<"size is "<<assoc.size()<<endl;
    // Erase a key with key as a parameter
    assoc.erase("beta");
    cout<<"Size is reduced to "<<assoc.size()<<endl;
    return 0;
}
