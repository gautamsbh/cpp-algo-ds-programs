// Pair is a simple Template Structure which contains
// Two Members first & second
// Pass values by its constructor
#include<iostream>
#include<utility>
using namespace std;
int main(void)
{
    pair<string,string> pa("Alok Sonkar","Crossing republik");
    // Now print Values
    // Remember here we have to print member of a structure
    // Thus we do not have to dereference it by -> (Pointer to a Structure)
    cout<<"\nFirst : "<<pa.first<<endl;
    cout<<"Second : "<<pa.second<<endl;
    // Now create a pair have string and an integer
    pair<string,int> alnum("Alok Sonkar",60);
    cout<<"\nFirst : "<<alnum.first<<endl;
    cout<<"Second : "<<alnum.second<<endl;
    return 0;
}
