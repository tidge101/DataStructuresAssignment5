#include "BSTNode.cpp"
#include "Person.cpp"

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
void optionFive(){

}

// Given a faculty id, print ALL the names and info of his/her advisees
void optionSix(){

}

// Add a new student
BST<Student>* optionSeven(){

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
    exit(0);
}
