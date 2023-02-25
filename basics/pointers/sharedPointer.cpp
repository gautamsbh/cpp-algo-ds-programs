#include<iostream>
#include<typeinfo>
#include<memory>
#include<algorithm>

using namespace std;

auto main() ->int {
  cout<<"Shared Pointer Operations : "<<endl;

  auto sp1 = shared_ptr<int>{};

  if(sp1) {
    cout<<"Shared Pointer sp1 is initialized "<<endl;
  } else {
    cout<<"Shared Pointer sp1 is not initialized "<<endl;
  }
  if(sp1.unique()) {
    cout<<"Shared Pointer sp1 is unique "<<endl;
  } else {
    cout<<"Shared Pointer sp1 is not unique "<<endl;
  }

  sp1 = make_shared<int>(1234);

  if(sp1) {
    cout<<"Shared Pointer sp1 is initialized "<<endl;
  } else {
    cout<<"Shared Pointer sp1 is not initialized "<<endl;
  }
  if(sp1.unique()) {
    cout<<"Shared Pointer sp1 is unique "<<endl;
  } else {
    cout<<"Shared Pointer sp1 is not unique "<<endl;
  }

  auto sp2 = sp1;
  cout<<"Shared Pointer sp1 counter "<<sp1.use_count() <<endl;
  if(sp1.unique()) {
    cout<<"Shared Pointer sp1 is unique "<<endl;
  } else {
    cout<<"Shared Pointer sp1 is not unique "<<endl;
  }

  cout<<"Shared Pointer sp2 counter "<<sp2.use_count() <<endl;
  if(sp2.unique()) {
    cout<<"Shared Pointer sp2 is unique "<<endl;
  } else {
    cout<<"Shared Pointer sp2 is not unique "<<endl;
  }

  sp2.reset();

  cout<<"Shared Pointer sp1 counter "<<sp1.use_count() <<endl;
  if(sp1.unique()) {
    cout<<"Shared Pointer sp1 is unique "<<endl;
  } else {
    cout<<"Shared Pointer sp1 is not unique "<<endl;
  }

  return 0;
}
