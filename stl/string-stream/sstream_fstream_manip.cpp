#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
int main(void)
{
    // grades.txt file Content 100 90 80 70 60s
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stringstream str;
    ifstream infile;
    int grades;
    int total=0;
    infile.open("C:\\Log\\data\\grades.txt");
    string line;
    getline(infile,line);
    str<<line;
    for(int i=0;i<5;i++)
    {
        str>>grades;
        total+=grades;
    }
    double average=(float)total/5;
    cout<<"Average : "<<average<<endl;
    return 0;
}
