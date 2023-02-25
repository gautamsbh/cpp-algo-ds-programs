#include<iostream>
#include<string>
#include<deque>
#include<fstream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<string> names;
    ifstream infile;
    infile.open("C:\\Log\\deque\\names.txt");
    string line;
    while(!infile.eof())
    {
        getline(infile,line);
        string::iterator it=line.end();
        --it;
        size_t pos=line.find(" "); // Here size_t is a data type which is used to store size of DT and ssize_t for signed size
        string name=line.substr(0,pos);
        if(*it == 'p')
        {
            names.push_front(name);
        }
        else
        {
            names.push_back(name);
        }
    }
    // Now print the elements of Dequeue for Iterator
    deque<string>::iterator tra=names.begin();
    while(tra!=names.end())
    {
        cout<<*tra<<endl;
        ++tra;
    }
    // Close the opened stream
    infile.close();
    return 0;
}
