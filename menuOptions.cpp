#include "BSTNode.cpp"
#include "Person.cpp"
BST<Faculty>* optionNine(BST<Faculty> *facTree);
// Print all students and their information (by ascending id #)
void optionOne(BST<Student>* studTree){

}

//  Print all faculty and their information (by ascending id #)
void optionTwo(BST<Faculty>* facTree){

}

// Find and display student information given the students id
void optionThree(BST<Student>* studTree, int id){
    if(studTree->search(id)){
        Node<Student>* temp = studTree->fetch(id);
        temp->element.outputStudentInfo();
    }
    else{cout << "This student could not be found! Returning to menu\n" << endl;}
}

// Find and display faculty information given the faculty id
void optionFour(BST<Faculty>* facTree, int id){
    if(facTree->search(id)){
        Node<Faculty>* temp = facTree->fetch(id);
        temp->element.outputFacultyInfo();
    }
    else{cout << "This faculty member could not be found! Returning to menu.\n" << endl;}
}

// Given a student’s id, print the name and info of their faculty advisor
void optionFive(BST<Student> *studTree, BST<Faculty> *facTree, int id){
  if(studTree->search(id)){
      Node<Student>* temp = studTree->fetch(id);
      int tempFacID = temp->element.getAdvisor();
      optionFour(facTree, tempFacID);
      }

  else{cout << "This student could not be found! Returning to menu\n" << endl;}
}

// Given a faculty id, print ALL the names and info of his/her advisees
void optionSix(BST<Faculty> *facTree, BST<Student> *studTree, int id){
  if(facTree->search(id)){
      Node<Faculty>* temp = facTree->fetch(id);
      vector<int>* tempVec = temp->element.getStudents();
      for (int i = 0; i < tempVec->size(); ++i){
        optionThree(studTree, (*tempVec)[i]);
      }
  }
}

// Add a new student
BST<Student>* optionSeven(BST<Faculty> *facTree, BST<Student> *studTree){
    string addFirstName;
    string addLastName;
    string addFullName;
    string addID;
    string addGPA;
    string addMajor;
    string addAdvisor;
    string addYN;

    cout << "Please enter student's first name: " << endl;
    cin >> addFirstName;
    cout << "Please emter student's last name: " << endl;
    cin >>addLastName;
    addFullName = addFirstName + " " + addLastName;
    cout << "Please enter student's ID Number: " << endl;
    cin >> addID;
    cout << "Please enter student's GPA: " << endl;
    cin >> addGPA;
    cout << "Please enter student's Major: " << endl;
    cin >> addMajor;
    cout << "Please enter student's advisor's ID Number: " << endl;
    cin >> addAdvisor;

    if(facTree->search(stoi(addAdvisor))){
        Node<Faculty>* temp = facTree->fetch(stoi(addAdvisor));
        vector<int> *tempVec = temp->element.getStudents();
        tempVec->push_back(stoi(addID));
      }
    else{
      cout << "Could not find faculty member. Would you like to add a new member? (Y/N)" << endl;
      cin >> addYN;
      if (addYN == "N" || addYN == "n"){
        cout << "Student will not be added. Returning to main menu." << endl;
        return studTree;}
      else{
        optionNine(facTree);
      }
    }
    Student* a = new Student(addFullName, stoi(addID), addMajor, stod(addGPA), stoi(addAdvisor));
    studTree->add(*a);
    cout << "Added student! ";
    a->outputStudentInfo();

    return studTree;

}

// Delete a student given the id
BST<Student>* optionEight(){

}

// Add a new faculty member
BST<Faculty>* optionNine(BST<Faculty> *facTree){
  string addName;
  string addID;
  string addDepartment;
  vector<int>* addStudents;

  cout << "Please enter faculty's name: " << endl;
  cin >> addName;
  cout << "Please enter faculty's ID Number: " << endl;
  cin >> addID;
  cout << "Please enter faculty's Department: " << endl;
  cin >> addDepartment;
  cout << "Please enter faculty's advisee ID numbers (type 0 to end entry): " << endl;
  int tempVal;
  while(cin>>tempVal){
    if (tempVal == 0){break;}
    else{addStudents->push_back(tempVal);}
  }


  Faculty* a = new Faculty(addName, stoi(addID), addDepartment, addStudents);
  facTree->add(*a);
  cout << "Added Faculty Member:: ";
  a->outputFacultyInfo();

  return facTree;
}

// Delete a faculty member given the id
BST<Faculty>* optionTen(){

}

// Change a student’s advisor given the student id and the new faculty id
BST<Student>* optionEleven(){

}

// Remove an advisee from a faculty member given the ids
BST<Faculty>* optionTwelve(){

}

// Rollback
void optionThirteen(){

}

// Exit
void optionFourteen(){
    exit(0);
}
