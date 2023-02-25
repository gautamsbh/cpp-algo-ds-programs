#### Templates in C++
A template is a simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need sort() for different data types. Rather than writing and maintaining the multiple codes, we can write one sort() and pass data type as a parameter.

> C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by keyword ‘class’.

How templates work?
Templates are expanded at compiler time. This is like macros. The difference is, compiler does type checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.
templates-cpp

![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/06/templates-cpp.jpg "Cpp Template Flow")

Function Templates We write a generic function that can be used for different data types. Examples of function templates are sort(), max(), min(), printArray().
Know more on Generics in C++

**Function Templates** We write a generic function that can be used for different data types. Examples of function templates are sort(), max(), min(), printArray().
Know more on Generics in C++

**Program**
```c++
#include <iostream> 
using namespace std; 
  
// One function works for all data types.  This would work 
// even for user defined types if operator '>' is overloaded 
template <typename T> 
T myMax(T x, T y) 
{ 
   return (x > y)? x: y; 
} 
  
int main() 
{ 
  cout << myMax<int>(3, 7) << endl;  // Call myMax for int 
  cout << myMax<double>(3.0, 7.0) << endl; // call myMax for double 
  cout << myMax<char>('g', 'e') << endl;   // call myMax for char 
  
  return 0; 
}
```

**Output**
```asm
7
7
g
```

**Class Templates** Like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc.

**Program**
```c++
#include <iostream> 
using namespace std; 
  
template <typename T> 
class Array { 
private: 
    T *ptr; 
    int size; 
public: 
    Array(T arr[], int s); 
    void print(); 
}; 
  
template <typename T> 
Array<T>::Array(T arr[], int s) { 
    ptr = new T[s]; 
    size = s; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 
  
template <typename T> 
void Array<T>::print() { 
    for (int i = 0; i < size; i++) 
        cout<<" "<<*(ptr + i); 
    cout<<endl; 
} 
  
int main() { 
    int arr[5] = {1, 2, 3, 4, 5}; 
    Array<int> a(arr, 5); 
    a.print(); 
    return 0; 
} 
```

**Output**
``` 1 2 3 4 5```

**Can there be more than one arguments to templates?**
Yes, like normal parameters, we can pass more than one data types as arguments to templates. The following example demonstrates the same.
```c++
template<class T, class U> 
class A  { 
    T x; 
    U y; 
public: 
    A() {    cout<<"Constructor Called"<<endl;   } 
}; 
```

**Can we specify default value for template arguments?**
Yes, like normal parameters, we can specify default arguments to templates. The following example demonstrates the same.
```c++
template<class T, class U = char> 
```

##### Q&A
**What is the difference between function overloading and templates?**
Both function overloading and templates are examples of polymorphism feature of OOP. Function overloading is used when multiple functions do similar operations, templates are used when multiple functions do identical operations.

**What happens when there is static member in a template class/function?**
Each instance of a template contains its own static variable. See Templates and Static variables for more details.

**What is template specialization?**
Template specialization allows us to have different code for a particular data type. See Template Specialization for more details.

**Can we pass non-type parameters to templates?**
We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying max or min values or any other constant value for a particular instance of a template. The important thing to note about non-type parameters is, they must be const. The compiler must know the value of non-type parameters at compile time. Because compiler needs to create functions/classes for a specified non-type value at compile time. In below program, if we replace 10000 or 25 with a variable, we get a compiler error. Please see this.

```c++
template <class T, int max> 
int arrMin(T arr[], int n) {} 
```

##### Templates and Static variables in C++
**Function templates and static variables:**
Each instantiation of function template has its own copy of local static variables. For example, in the following program there are two instances: void fun(int ) and void fun(double ). So two copies of static variable i exist.
