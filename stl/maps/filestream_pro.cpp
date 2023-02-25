#include<iostream>
#include<cstdlib>   // Used For exit & dynamic memory allocations
#include<map>
#include<fstream>
using namespace std;
void showNumber(map<string,string> phonelist)
{
    string name;
    cin>>name;
    cout<<"Phone Number of "<<name<<" : "<<phonelist[name]<<endl;
}
void showMenu()
{
    cout<<"1 : Get Number"<<endl;
    cout<<"2 : Quit"<<endl;
    cout<<endl;
    cout<<"Enter the Choice"<<endl;
}
string getName(string line)
{
    int pos=line.find("."); // Find fives the First occurrence of Symbol in String like indexOf operator
    return line.substr(0,pos); // Substring function to extract Sub-String for String
}
string getNumber(string line)
{
    int pos=line.find(".");
    return line.substr(pos+1);
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,string> phonelist;
    // Creating Input Stream to read File
    ifstream infile("c:\\Log\\data\\phonelist.dat");
    string line,name,number;
    while(!infile.eof())
    {
        getline(infile,line);
        name= getName(line);
        number= getNumber(line);
        phonelist[name]=number;
    }
    infile.close();
    int choice=1;
    while(choice!=2)
    {
        showMenu();
        cin>>choice;
        if(choice==1)
        {
            showNumber(phonelist);
        }
    }
    return 0;
}
