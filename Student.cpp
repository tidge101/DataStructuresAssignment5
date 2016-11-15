using namespace std;
#include "Person.cpp"
class Student : public Person{
  private:
    double GPA;
    int AdvisorID;
    string Major;
  public:
    Student();
    Student(double GPAInput, int AdvisorNum);
    ~Student();

    void setGPA(double input);
    double getGPA();

    void setAdvisor(int input);
    int getAdvisor();

    void setMajor(string input);
    string getMajor();

    void outputStudentInfo();
};

Student::Student(double GPAInput, int AdvisorNum){
  setGPA(GPAInput);
  setAdvisor(AdvisorNum);
}

void Student::outputStudentInfo(){
  cout << "ID: " << getID() << " Name: " << getName() << " Advisor ID: ";
  cout << getAdvisor() << " GPA: " << getGPA() << " Major: " << getMajor() << endl;
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
