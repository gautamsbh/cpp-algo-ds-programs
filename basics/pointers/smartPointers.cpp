#include<iostream>
#include<memory>
#include<typeinfo>

using namespace std;

struct BodyMass {
  int Id;
  float Weight;

  BodyMass(int id, float weight) : Id(id), Weight(weight) {
    cout<<"Body mass is constructed! "<<endl;
    cout<<"Id = "<<Id << endl;
    cout<<"Weight = "<<Weight<<endl;
  }

  ~BodyMass {
    cout<<"Body Mass is destructed "<<endl;
  }
};

auto main() -> int {
  // Smart pointer are used to manage memory leaks and organize memory
  auto up1 = unique_ptr<int>{};
  auto up2 = unique_ptr<int>{ nullptr };
  auto ip3 = unique_ptr<int>{ new int {1234} };

  // you make unique pointer to existing data type
  auto up4 = make_unique<int>(1234);
  auto myWeight = make_unique<BodyMass>(1, 12.34f);
  cout<<endl<<"Doing Something!!!"<<endl;

  return 0;
}
