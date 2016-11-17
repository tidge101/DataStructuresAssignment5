#include "BSTNode.cpp"
#include "Person.cpp"

// Print all students and their information (by ascending id #)
void optionOne(){

}

//  Print all faculty and their information (by ascending id #)
void optionTwo(){

}

// Find and display student information given the students id
void optionThree(){

}

// Find and display faculty information given the faculty id
void optionFour(){

}

// Given a student’s id, print the name and info of their faculty advisor
void optionFive(){

}

// Given a faculty id, print ALL the names and info of his/her advisees
void optionSix(){

}

// Add a new student
BST<Student>* optionSeven(BST<Student> *studTree){
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
    studTree->add(*a);
    cout << "Added student:: ";
    a->outputStudentInfo();

    return studTree;

}

// Delete a student given the id
BST<Student>* optionEight(){

}

// Add a new faculty member
BST<Faculty>* optionNine(){

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

}
