#include<iostream>
#include<deque>
using namespace std;
int find(deque<string> line, string names)
{
    for(int i=0;i<line.size();i++)
    {
        // Use at for Array Vector Dequeue for Dereferencing because it Checks array bound
        if(line.at(i)==names)
        {
            return i;
        }
    }
    return -1;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<string> line;
    line.push_back("David");
    line.push_back("Reogers");
    line.push_back("Shaina");
    line.push_back("Samuels");
    line.push_back("Ikka");
    string name;
    cin>>name;
    int pos=find(line,name);
    if(pos > -1)
    {
        cout<<"Found at Position\t"<<pos<<endl;
    }
    else
    {
        cout<<"Not Found";
    }
    // Insert an Element at a Given position
    // use Iterator
    deque<string>::iterator it=line.begin();
    ++it;
    line.insert(it,"Gautam");
    // Print Whole Dequeue
    deque<string>::iterator tra=line.begin();
    while(tra!=line.end())
    {
        cout<<*tra<<endl;
        ++tra;
    }
    return 0;
}
