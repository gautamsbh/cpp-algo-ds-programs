#include<iostream>
#include<cmath>
#include<string>

using namespace std;

/**
* Check Generic class
*/
template<class genType, int size = 50>
class genClass {
protected:
    genType storage[size];
  public:
    void print() {
        for(int i=0;i<50;i++) {
          cout<<storage[i]<<" ";
        }
    }
};
/**
* Check specific class
*/
class Check {
public:
  Check(int len, string str) {
    datamember1 =len;
    charmap = str;
  }
  void print() {
    datamember2 = charmap.length();
    cout<<"Print the Data: "<<charmap<<"\nLenght is: "<<datamember1<<"\nFunction Defined Lenght: "<<datamember2<<endl;
  }
protected:
  string charmap;
  int datamember1;
  int datamember2;
};
int main(int argc, char *argv[]) {
  Check obj1(12, "Hello World");
  genClass<int> intObject;
  genClass<float> floatObject;
  obj1.print();
  intObject.print();cout<<endl;
  floatObject.print();
  return 0;
}
