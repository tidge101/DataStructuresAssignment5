#include "BSTNode.cpp"
#include "Person.cpp"

BST<Student>* studTree = new BST<Student>();


Student* stud = new Student(3.54, 10);
stud->setName("Dillon");
stud->setID(5);
stud->setMajor("Computer Science");
Node<Student*>* studentNode = new Node(stud);


studTree->add(student);

studTree->print();
