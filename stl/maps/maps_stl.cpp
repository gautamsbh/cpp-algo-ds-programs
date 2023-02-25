#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include<string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<string, int> result;
    map<string,int>::iterator itr;
    int queries,choice, value;
    string key; cin>>queries;
    for(int i=0;i<queries;i++) {
        cin>>choice;
        if(choice == 1) {
            cin>>key>>value;
            itr=result.find(key);
            value = itr != result.end() ? value + itr->second : value;
            result[key] = value;
        } else if(choice == 2) {
            cin>>key;
            result.erase(key);
        } else {
            cin>>key;
            itr=result.find(key);
            itr != result.end() ? cout<<itr->second<<endl : cout<<0<<endl;
        }
    }
    return 0;
}
