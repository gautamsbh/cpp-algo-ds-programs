#include<iostream>
#include<deque>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<string> line;
    line.push_back("Customer 1");
    line.push_back("Customer 2");
    line.push_back("Customer 3");
    // create an Iterator to Print Dequeue
    deque<string>::iterator it=line.begin();
    while(it!=line.end())
    {
        cout<<*it<<endl;
        ++it;
    }
    // From Now it is Working like Ordinary Queue
    // Now pop from back & front and then printing Result after alteration
    line.pop_back();
    line.pop_front();
    // Create an Iterator
    cout<<"\n\n After POP operation on Dequeue"<<endl;
    cout<<" Size Reduced to "<<line.size()<<"\n\n"<<endl;
    deque<string>::iterator tra=line.begin();
    while(tra!=line.end())
    {
        cout<<*tra<<endl;
        ++tra;
    }
    return 0;
}
