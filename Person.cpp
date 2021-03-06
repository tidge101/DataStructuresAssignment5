#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

Person::Person(){}

Person::~Person(){}

void Person::outputInfo(){
  cout << ID << " :: " << Name << endl;
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

//////////////////////////////////////////////////
//////////////////////////////////////////////////

class Student : public Person{
  private:
    double GPA;
    int AdvisorID;
    string Major;
  public:
    Student(){};
    Student(string name, int IDNum, string major, double GPAInput, int AdvisorNum);
    ~Student(){};

    void operator = (Student* S) {
        setName(S->getName());
        setAdvisor(S->getAdvisor());
        setGPA(S->getGPA());
        setMajor(S->getMajor());
    }

    void setGPA(double input);
    double getGPA();

    void setAdvisor(int input);
    int getAdvisor();

    void setMajor(string input);
    string getMajor();

    void outputStudentInfo();
};

Student::Student(string name, int IDNum, string major, double GPAInput, int AdvisorNum){
  setGPA(GPAInput);
  setAdvisor(AdvisorNum);
  setMajor(major);
  setName(name);
  setID(IDNum);
}

void Student::outputStudentInfo(){
  cout << "Name: " << getName() << endl;
  cout << "ID: " << getID() << endl;
  cout << "Advisor ID: " << getAdvisor() << endl;
  cout << "GPA: " << getGPA() << endl;
  cout << " Major: " << getMajor() << endl;
}

void Student::setGPA(double input){
  GPA = input;
}

double Student::getGPA(){
  return GPA;
}

void Student::setAdvisor(int input){
  AdvisorID = input;
}

int Student::getAdvisor(){
  return AdvisorID;
}

void Student::setMajor(string input){
  Major = input;
}
string Student::getMajor(){
  return Major;
}

///////////////////////////////////////////
///////////////////////////////////////////



class Faculty : public Person{
  private:
    string department;
    vector<int> studentIDs;

  public:
    Faculty(){};
    Faculty(string name, int id, string depInput, vector<int>* studentList);
    ~Faculty(){};

    void operator = (Faculty* F) {
        setName(F->getName());
        setID(F->getID());
        setStudents(F->getStudents());
        setDepartment(F->getDepartment());
    }

    void VectorToString(vector<int> a);

    void setDepartment(string input);
    string getDepartment();

    void setStudents(vector<int>* input);
    vector<int>* getStudents();

    void outputFacultyInfo();

};

Faculty::Faculty(string name, int id, string depInput, vector<int>* studentList){
  setDepartment(depInput);
  setStudents(studentList);
  setID(id);
  setName(name);
}

void Faculty::VectorToString(vector<int> a){
  for (int i=0;i<a.size();++i){
    cout << a[i] << " ; ";
  }
}

void Faculty::outputFacultyInfo(){
  cout << "ID: " << getID() << " Name: " << getName() << " Students' IDs: ";
  VectorToString(*getStudents());
  cout << endl << " Department: " << getDepartment() << endl;
}
void Faculty::setDepartment(string input){
  department = input;
}

string Faculty::getDepartment(){
  return department;
}

void Faculty::setStudents(vector<int>* input){
  studentIDs = *input;
}

vector<int>* Faculty::getStudents(){
  return &studentIDs;
}
