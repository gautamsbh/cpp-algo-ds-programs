#include<iostream>
#include<algorithm>
#include<memory>
#include<typeinfo>

using namespace std;

struct BodyMass {
  int Id;
  float Weight;
  BodyMass(int id, float weight) : Id(id), Weight(weight)  {
    cout<<"Body Mass is contructed :"<<endl;
    cout<<"Id is : "<<Id<<endl;
    cout<<"Weight is : "<<weight<<endl;
  }

  ~BodyMass() {
    cout<<"BodyMass is destructed : "<<endl;

  }
};

unique_ptr<BodyMass> GetBodyMass() {
  return make_unique<BodyMass>(1, 1.5f);
}

unique_ptr<BodyMass> UpdateBodyMass(unique_ptr<BodyMass> bodyMass) {
  bodyMass->Weight += 1.0f;
  return bodyMass;
}

auto main() -> int {
  cout<<"Unique Pointer Object : "<<endl;
  auto myWeight = GetBodyMass();
  cout<<"Current Weight : "<<myWeight->Weight << endl;
  myWeight = UpdateBodyMass(move(myWeight));
  cout<<"Updated Weight : "<<myWeight->Weight << endl;

  return 0;
}
