#include "BSTNode.cpp"
#include "Person.cpp"

/* Compute the "height" of a tree -- the number of
 nodes along the longest path from the root node
 down to the farthest leaf node.*/
int heightStudent(Node<Student>* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = heightStudent(node->left);
        int rheight = heightStudent(node->right);
        
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

int heightFaculty(Node<Faculty>* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = heightFaculty(node->left);
        int rheight = heightFaculty(node->right);
        
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}


/* Print nodes at a given level */
void printGivenLevelStudent(Node<Student>* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        root->element.outputStudentInfo();
    else if (level > 1)
    {
        printGivenLevelStudent(root->left, level-1);
        printGivenLevelStudent(root->right, level-1);
    }
}

/* Print nodes at a given level */
void printGivenLevelFaculty(Node<Faculty>* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        root->element.outputFacultyInfo();
    else if (level > 1)
    {
        printGivenLevelFaculty(root->left, level-1);
        printGivenLevelFaculty(root->right, level-1);
    }
}

/* Function to print level order traversal a tree*/
void printLevelOrderStudent(Node<Student>* root)
{
    int h = heightStudent(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevelStudent(root, i);
}

/* Function to print level order traversal a tree*/
void printLevelOrderFaculty(Node<Faculty>* root)
{
    int h = heightFaculty(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevelFaculty(root, i);
}

BST<Faculty>* optionNine(BST<Faculty> *facTree);
// Print all students and their information (by ascending id #)
void optionOne(BST<Student>* studTree){
    cout << endl << "All students: " << endl;
    printLevelOrderStudent(studTree->getRoot());
    cout << endl;
}

//  Print all faculty and their information (by ascending id #)
void optionTwo(BST<Faculty>* facTree){
    cout << endl << "All faculty: " << endl;
    printLevelOrderFaculty(facTree->getRoot());
    cout << endl;
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
    cout << "\nAdded student: ";
    a->outputStudentInfo();
    cout << endl;

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
  cout << "\nAdded Faculty Member:: ";
  a->outputFacultyInfo();
    cout << endl;

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
