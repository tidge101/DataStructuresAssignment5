#include <iostream>
#include "menuOptions.cpp"

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

int main(int argc, char* argv[]){
    // Check for existence of facultyTable and studentTable files, read BST's masterFaculty and masterStudent from these files if they exist, else create new BST's
    bool facultyDoesExist = false, studentDoesExist =false;
    // Check here
    if(!facultyDoesExist){
        BST masterFaculty = new BST();
    }
    else{
        // masterFaculty = BST from file
    }
    if(!studentDoesExist){
        BST masterStudent = new BST();
    }
    else{
        // masterStudent = BST from file
    }
    
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
        
        switch choice{
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
}