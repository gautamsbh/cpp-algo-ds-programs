#include<iostream>
#include<memory>
#include<algorithm>
#include<typeinfo>

using namespace std;

auto main() -> int {

  cout<<"Weak Pointer is Initialzed : "<<endl;

  auto sp1 = make_shared<int>(1234);

  auto wp1 = weak_ptr<int>{ sp1 };

  if(wp1.expired()) {
    cout<<"Wp1 is expired"<<endl;
  } else {
    cout<<"Wp2 is not expired"<<endl;
  }

  cout<<"Weak Pointer wp1 counter : "<<wp1.use_count()<<endl;

  if(auto locked = wp1.lock()) {
    cout<<"Weak Pointer is Locked value : "<<*locked<<endl;
  } else {
    cout<<"Wp1 is unlocked "<<endl;
    wp1.reset();
  }

  cout<<endl;

  sp1 = nullptr;

  if(wp1.expired()) {
    cout<<"Wp1 is expired"<<endl;
  } else {
    cout<<"Wp2 is not expired"<<endl;
  }

  cout<<"Weak Pointer wp1 counter : "<<wp1.use_count()<<endl;

  if(auto locked = wp1.lock()) {
    cout<<"Weak Pointer is Locked value : "<<*locked<<endl;
  } else {
    cout<<"Wp1 is unlocked "<<endl;
    wp1.reset();
  }

  return 0;
}
