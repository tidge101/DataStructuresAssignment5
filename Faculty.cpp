using namespace std;
// #include "Person.cpp"
#include <vector>

class Faculty : public Person{
  private:
    string department;
    vector<int> studentIDs;

  public:
    Faculty();
    Faculty(string depInput, vector<int> studentList);
    ~Faculty();

    void setDepartment(string input);
    string getDepartment();

    void setStudents(vector<int> input);
    vector<int> getStudents();

    void outputFacultyInfo();

};

Faculty::Faculty(string depInput, vector<int> studentList){
  setDepartment(depInput);
  setStudents(studentList);
}

void Faculty::outputFacultyInfo(){
  cout << "ID: " << getID() << " Name: " << getName() << " Students' IDs: ";
  cout << getStudents() << " Department: " << getDepartment() << endl;
}
void Faculty::setDepartment(string input){
  department = input;
}

string Faculty::getDepartment(){
  return department;
}

void Faculty::setStudents(vector<int> input){
  studentIDs = input;
}

vector<int> Faculty::getStudents(){
  return studentIDs;
}
