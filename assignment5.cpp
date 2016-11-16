#include <iostream>
#include <fstream>
#include <stack>
#include "menuOptions.cpp"
#include "person.cpp"
<<<<<<< HEAD
// #include "Student.cpp"
// #include "Faculty.cpp"
#include "BSTNode.cpp"
=======
>>>>>>> f397e43cbfb8c1b6f6d1162cf11caa716143ee76

void printMenu(){
    cout << "Menu" << endl
    << "1: Print all students and their information (sorted by ascending id #)" << endl
    << "2: Print all faculty and their information (sorted by ascending id #)" << endl
    << "3: Find and display student information given the students id" << endl
    << "4: Find and display faculty information given the faculty id" << endl
    << "5: Given a student’s id, print the name and info of their faculty advisor" << endl
    << "6: Given a faculty id, print ALL the names and info of his/her advisees" << endl
    << "7: Add a new student" << endl
    << "8: Delete a student given the id" << endl
    << "9: Add a new faculty member" << endl
    << "10: Delete a faculty member given the id" << endl
    << "11: Change a student’s advisor given the student id and the new faculty id" << endl
    << "12: Remove an advisee from a faculty member given the ids" << endl
    << "13: Rollback" << endl
    << "14: Exit" << endl;
}

bool exists(const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

BST<Faculty>* readFacultyBST(string filename){
    BST<Faculty>* bst = new BST();
    ifstream inFile;
<<<<<<< HEAD


    // Read BST info from file and
    inFile.open(filename);
    while(!inFile.eof()){
        Node* newNode = new Node();

=======
    
    // Read BST info from file and
    inFile.open(filename);
    while(!inFile.eof()){
        Node<Faculty>* newNode = new Node<Faculty>();
        
>>>>>>> f397e43cbfb8c1b6f6d1162cf11caa716143ee76
    }

    //Populate BST with info read

    return bst;
}

BST<Student>* readStudentBST(string filename){
    BST<Student>* bst = new BST<Student>();
    ifstream inFile;

    // Read BST info from file and
    inFile.open(filename);
    while(!inFile.eof()){
<<<<<<< HEAD
        Node* newNode = new Node();

=======
        Node<Student>* newNode = new Node();
        
>>>>>>> f397e43cbfb8c1b6f6d1162cf11caa716143ee76
    }

    //Populate BST with info read
<<<<<<< HEAD

=======
    
>>>>>>> f397e43cbfb8c1b6f6d1162cf11caa716143ee76
    return bst;
}

int main(int argc, char* argv[]){
    // Check for existence of facultyTable and studentTable files, read BST's masterFaculty and masterStudent from these files if they exist, else create new BST's
    bool facultyDoesExist = exists("facultyTable.txt"), studentDoesExist = exists("studentTable.txt");
<<<<<<< HEAD
    if(!facultyDoesExist){BST masterFaculty = new BST();}
    else{masterFaculty = readFacultyBST("facultyTable.txt");}
    if(!studentDoesExist){BST masterStudent = new BST();}
    else{masterStudent = readStudentBST("studentTable.txt");}
=======
    BST<Faculty>* masterFaculty = new BST<Faculty>();
    BST<Student>* masterStudent = new BST<Student>();
    if(facultyDoesExist){masterFaculty = readFacultyBST("facultyTable.txt");}
    if(studentDoesExist){masterStudent = readStudentBST("studentTable.txt");}
>>>>>>> f397e43cbfb8c1b6f6d1162cf11caa716143ee76

    // Main functionality
    while(true){
        printMenu();

        int choice = 0;
        cout << "Please choose an option from the menu(1-14): " << endl;
        while(cin >> choice){
            if(choice < 1 || choice > 14){
                cout << "Please enter a number between 1 and 14: " << endl;
            }
            else{break;}
        }

        switch(choice){
        case 1: optionOne();
            break;
        case 2: optionTwo();
            break;
        case 3: optionThree();
            break;
        case 4: optionFour();
            break;
        case 5: optionFive();
            break;
        case 6: optionSix();
            break;
        case 7: optionSeven();
            break;
        case 8: optionEight();
            break;
        case 9: optionNine();
            break;
        case 10: optionTen();
            break;
        case 11: optionEleven();
            break;
        case 12: optionTwelve();
            break;
        case 13:
            optionThirteen();
            break;
        case 14: optionFourteen();
            break;
        }
    }

    // Write BSTs to files if they exist
    if(!masterFaculty->empty()){
        // Traverse and output all info to facultyTable.txt that must be read when deserializing
        masterFaculty->outputPreorderFacultyToFile(masterFaculty->getRoot(), "facultyTable.txt");
    }
<<<<<<< HEAD
    if(!masterStudent.empty()){
        masterStudent.outputPreorderStudentToFile(getRoot, "studentTable.txt");
=======
    if(!masterStudent->empty()){
        masterStudent->outputPreorderStudentToFile(masterStudent->getRoot(), "studentTable.txt");
>>>>>>> f397e43cbfb8c1b6f6d1162cf11caa716143ee76
    }
}
