using namespace std;
#include <iostream>

class Person{
  private:
    string Name;
    int ID;
  public:
    Person();
    Person(string n, int number);
    ~Person();

    string getName();
    int getID();

    void setName(string n);
    void setID(int number);
    void outputInfo();
};

Person::Person(string n, int number){
  setName(n);
  setID(number);
}

void Person::outputInfo(){
  cout << id << " :: " << name << endl;
}

string Person::getName(){
  return Name;
}

int Person::getID(){
  return ID;
}

void Person::setName(string n){
  Name = n;
}

void Person::setID(int number){
  ID = number;
}
