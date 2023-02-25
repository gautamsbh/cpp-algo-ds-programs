#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
typedef array<string,5> FiveString;
int main()
{
    FiveString sam={"he","lo","wo","rl","dl"};
    cout<<tuple_size<FiveString>::value;
    tuple_element<1,FiveString>::type;
    cout<<get<1>(sam);
    return 0;
}
