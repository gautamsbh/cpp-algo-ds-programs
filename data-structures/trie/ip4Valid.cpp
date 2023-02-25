#include<iostream>
#include<string>
#include<cstdlib>
#define CHAR_TO_INDEX(CH) ((int)CH - (int)'0')
using namespace std;
// Function to Process Valid Octet
bool valid_octet(int octet)
{
    if(!(octet>=0 && octet<=255))
        return false;
    return true;
}
// Function for Character except Numeric & .
bool numeric_check(int num)
{
    if(!(num>=0 && num<=9))
        return false;
    return true;
}
// Function to Validate IP Address of Version 4
bool ip_address(string ip)
{
    int octet=1; int dot=0;
    // Rules for Valid Valid IP Address
    // 1) IP Address can Have length 7 - 15
    // 2) IP Address can have at-most 3 (.) Delimiter.
    // 3) IP Each Octet lies Between 0-255
    // 4) IP address octet cannot have any leading zeros
    // 5) IP Address Cannot Have Alphabets
    if(!(ip.size()>=7 && ip.size()<=15))
        return false;
    octet=CHAR_TO_INDEX(ip[0]); if(!numeric_check(octet)) return false;
    for(int i=1;i<ip.size();i++)
    {
        if(ip[i]=='.')
        {
            if(!valid_octet(octet))
                return false;
            octet=CHAR_TO_INDEX(ip[i+1]);
            if(!numeric_check(octet)) return false;
            i++; dot++;
            continue;
        }
       if(!(CHAR_TO_INDEX(ip[i])>=0 && CHAR_TO_INDEX(ip[i])<=9))
            return false;
       if(octet==0)
            return false;
       octet=octet*10+CHAR_TO_INDEX(ip[i]);
    }
    if(dot!=3)
        return false;
    return true;
}
int main(void)
{
    string ip;
    while(1)
    {
    cin>>ip;
    if(ip_address(ip)==true)
        cout<<"Valid IP Address : "<<ip<<"\n\n";
    else
        cout<<"Invalid IP Address : "<<ip<<"\n\n";
    }
}
