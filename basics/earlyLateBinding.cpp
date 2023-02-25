#include<iostream>

using namespace std;

/**
Early Binding:
Binding means to match the function call with the correct definition by the compiler.
At compile time or run time.

Early binding compiler matches the function call with the correct function definition at compile time
It is also called Static Binding or Compile Time Binding. By Default, compiler goes for the function definition
called during compile time. So, all the function call are due to early binding.

In Method Overriding the Early Binding is responsible for function dispactcging,

*/

/**
Late Binding:
In Late binding the function definition is matched at runtime. It is also called dynamic binding
or runtime binding. In Late binding the compiler identifies type of object at runtime and the
matches the function call. By, default early binding takes place. this can be achieved by
virtual function.

Virtual Function:
Virtual function is a member function of the base class which is overriden by derived class.
The compiler performs late binding on this function. To make function virtual, just add
keyword virtual before function.

Note: we can also call private functionof derived class from a base class pointer by declaring
that function in the base class as virtual..

Compiler checks whether member is public, protected, private at compile time and not at runtime.

class Animal {
public:
    virtual void sound() {
      cout<<"This is a Animal Sound"<<endl;
    }
};

class Dog: public Animal {
public:
    void sound() {
      cout<<"Dog Bark"<<endl;
    }
};

class Animal {
public:
    virtual void sound() {
      cout<<"This is a Animal Sound"<<endl;
    }
};

class Dog: public Animal {
private:
    virtual void sound() {
      cout<<"Dog Bark"<<endl;
    }
};

Pure virtual function is a function which has no definition. Pure virtual function is
also called abstract functions.

To create a pure virtual function, we assign a value 0 to the function as follows.

virtual void sound() = 0;

Here sound() is a pure virtual area.
*/

/**
Memory Management:
Summary of what static, heap, and stack memory are:
A static variable is basically a global variable, even if you cannot access it globally. Usually there is an address for it that is in the executable itself. There is only one copy for the entire program. No matter how many times you go into a function call (or class) (and in how many threads!) the variable is referring to the same memory location.

The heap is a bunch of memory that can be used dynamically. If you want 4kb for an object then the dynamic allocator will look through its list of free space in the heap, pick out a 4kb chunk, and give it to you. Generally, the dynamic memory allocator (malloc, new, et c.) starts at the end of memory and works backwards.

Explaining how a stack grows and shrinks is a bit outside the scope of this answer, but suffice to say you always add and remove from the end only. Stacks usually start high and grow down to lower addresses. You run out of memory when the stack meets the dynamic allocator somewhere in the middle (but refer to physical versus virtual memory and fragmentation). Multiple threads will require multiple stacks (the process generally reserves a minimum size for the stack).

When you would want to use each one:
Statics/globals are useful for memory that you know you will always need and you know that you don't ever want to deallocate. (By the way, embedded environments may be thought of as having only static memory... the stack and heap are part of a known address space shared by a third memory type: the program code. Programs will often do dynamic allocation out of their static memory when they need things like linked lists. But regardless, the static memory itself (the buffer) is not itself "allocated", but rather other objects are allocated out of the memory held by the buffer for this purpose. You can do this in non-embedded as well, and console games will frequently eschew the built in dynamic memory mechanisms in favor of tightly controlling the allocation process by using buffers of preset sizes for all allocations.)

Stack variables are useful for when you know that as long as the function is in scope (on the stack somewhere), you will want the variables to remain. Stacks are nice for variables that you need for the code where they are located, but which isn't needed outside that code. They are also really nice for when you are accessing a resource, like a file, and want the resource to automatically go away when you leave that code.

Heap allocations (dynamically allocated memory) is useful when you want to be more flexible than the above. Frequently, a function gets called to respond to an event (the user clicks the "create box" button). The proper response may require allocating a new object (a new Box object) that should stick around long after the function is exited, so it can't be on the stack. But you don't know how many boxes you would want at the start of the program, so it can't be a static.

Garbage Collection
I've heard a lot lately about how great Garbage Collectors are, so maybe a bit of a dissenting voice would be helpful.

Garbage Collection is a wonderful mechanism for when performance is not a huge issue. I hear GCs are getting better and more sophisticated, but the fact is, you may be forced to accept a performance penalty (depending upon use case). And if you're lazy, it still may not work properly. At the best of times, Garbage Collectors realize that your memory goes away when it realizes that there are no more references to it (see reference counting). But, if you have an object that refers to itself (possibly by referring to another object which refers back), then reference counting alone will not indicate that the memory can be deleted. In this case, the GC needs to look at the entire reference soup and figure out if there are any islands that are only referred to by themselves. Offhand, I'd guess that to be an O(n^2) operation, but whatever it is, it can get bad if you are at all concerned with performance. (Edit: Martin B points out that it is O(n) for reasonably efficient algorithms. That is still O(n) too much if you are concerned with performance and can deallocate in constant time without garbage collection.)

Personally, when I hear people say that C++ doesn't have garbage collection, my mind tags that as a feature of C++, but I'm probably in the minority. Probably the hardest thing for people to learn about programming in C and C++ are pointers and how to correctly handle their dynamic memory allocations. Some other languages, like Python, would be horrible without GC, so I think it comes down to what you want out of a language. If you want dependable performance, then C++ without garbage collection is the only thing this side of Fortran that I can think of. If you want ease of use and training wheels (to save you from crashing without requiring that you learn "proper" memory management), pick something with a GC. Even if you know how to manage memory well, it will save you time which you can spend optimizing other code. There really isn't much of a performance penalty anymore, but if you really need dependable performance (and the ability to know exactly what is going on, when, under the covers) then I'd stick with C++. There is a reason that every major game engine that I've ever heard of is in C++ (if not C or assembly). Python, et al are fine for scripting, but not the main game engine.

*/

class Animal {
public:
    void sound() {
      cout<<"This is a Animal Sound"<<endl;
    }
};

class Dog: public Animal {
public:
    void sound() {
      cout<<"Dog Bark"<<endl;
    }
};


int main(int argc, char *argv[]) {
  Animal *a;
  Dog d;
  a = &d; // Base class can point to the derived class. Early Binding
  a -> sound();
  return 0;
}
