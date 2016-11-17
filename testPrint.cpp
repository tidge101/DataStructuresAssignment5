#include "BSTNode.cpp"
#include "Person.cpp"

void addStudent(BST<Student>* tree){
  string addName;
  string addID;
  string addGPA;
  string addMajor;
  string addAdvisor;

  cout << "Please enter student's name: " << endl;
  cin >> addName;
  cout << "Please enter student's ID Number: " << endl;
  cin >> addID;
  cout << "Please enter student's GPA: " << endl;
  cin >> addGPA;
  cout << "Please enter student's Major: " << endl;
  cin >> addMajor;
  cout << "Please enter student's advisor's ID Number: " << endl;
  cin >> addAdvisor;

  Student* a = new Student(addName, stoi(addID), addMajor, stod(addGPA), stoi(addAdvisor));
  tree->add(*a);
  cout << "Added student:: ";
  a->outputStudentInfo();
}

int main(){

    BST<Student>* studTree = new BST<Student>();
    addStudent(studTree);

    // Student* stud = new Student(3.54, 10);
    // stud->setName("Dillon");
    // stud->setID(5);
    // stud->setMajor("Computer Science");
    //Node<Student>* studentNode = new Node<Student>(stud);


    // studTree->add(*stud);

    studTree->getRoot()->element.outputStudentInfo();

//    studTree->deleteValue(*stud);
//
//    studTree->print();
}
