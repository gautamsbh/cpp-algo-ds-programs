#include<iostream>
#include<cmath>
#include<string>

using namespace std;

/** Namespace Exception */
namespace exception {
  class Exception {
  public:
    string message;
    Exception(string e) {
      message = "Exception Occured: ";
    }
  };
};

/** Namespace Dev */
namespace dev {
  class ListNode {
    friend class List;
  protected:
    int data;
    ListNode *link;
  };

  class List {
  public:
      /** Contructor for Class List: responsible for Initialization: Activates on new keyword encountered */
    List() {
      cout<<"List Object is Instantiated: "<<endl;
    }
    /** Destructor for class List: Responsible for Memory Management Freeing Mem: Activates when delete is encountered */
    ~List() {
      cout<<"List Object get Desttructed: "<<endl;
    }
    // Implement your Single or Forward Linked List Functions
  protected:
    ListNode *root;
  };
};
/** Driver Program: Entry function of the program */
int main(int argc, char *argv[]) {
/** Exception Handling for Compile time and runtime errors handling */
  try {
      dev::List *myList = new dev::List();
      if(!myList) {
          throw new exception::Exception("Error Thrown");
      }
      delete myList;
  }
  /** Ellipsis used for handling default exception */
  /** No Need to for Resource Deallocation as this catch block destroys everything in try block */
  catch(exception::Exception *exp) {
    cout<<"Object Instantiation Failed: "<<exp->message<<endl;
  }
/** C++ Donot have any finally block encountered after try-catch block: It improves code: Comply with DRY rule */
  return 0;
}
