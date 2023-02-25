#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Shape
{
    public:
        int  edge_length;
        virtual int circumference()
        {
            cout<<"Circumference of Base Class\n";
            return 0;
        }
};
class Triangle : public Shape
{
    public:
        int circumference()
        {
            cout<<"Circumference of Traingle Class\n";
            return 3*edge_length;
        }
};
// driver Program
int main(void)
{
    Shape *x=new Shape();
    x->circumference();
    Shape *y=new Triangle();
    y->circumference();
    return 0;
}
