#include<iostream>
#include<sstream>
using namespace std;
class Student
{
    string first,middle,last;
    int age;
public:
    Student()   // Default Constructor
    {
        cout<<"Pass Parameter to Object"<<endl;
    }
    Student(string f,string m,string l,int ag)   // Paramatrized Constructor Contructor
    {
        first=f;
        middle=m;
        last=l;
        age=ag;
    }
    string toString()
    {
        stringstream ss;
        ss<<first<<" "<<middle<<" "<<last<<" "<<age;
        // You have to convert stringstream to only string call str() method
        return ss.str();
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Student ob("Gautam","Singh","Bhadauria",22);
    cout<<ob.toString()<<endl;
    return 0;
}
