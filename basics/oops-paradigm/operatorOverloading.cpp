#include<iostream>
#include<cmath>

using namespace std;

class Newton {
protected:
  int x, y;
public:
  Newton(int i=0, int j =0) {
    x = i;
    y = j;
  }
   Newton* operator + (Newton* n1) {
     Newton *result = new Newton(x+ n1->x, y + n1->y);
     return result;
   }
   operator << (Newton* n1) {
     cout<<"Object Output is : "<<n1->x<<" "<<n1->y<<endl;
   }
};

int main() {
  Newton *n1 = new Newton(2, 4);
  Newton *n2 = new Newton(5, 7);
  cout<<(n1+n2);
  return 0;
}
