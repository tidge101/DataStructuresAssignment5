#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

template <class T>
struct Node {
    T value;
    Node *left;
    Node *right;
    int nodeKey;

    Node(T val) {
        this->value = val;
    }

    Node(T val, Node<T> left, Node<T> right) {
        this->nodeKey = val.getID();
        this->value = val;
        this->left = left;
        this->right = right;
    }
};

template <class T>
class BST {

    private:
    Node<T>* root;

    void addHelper(Node<T> *root, T personObj) {
        int val = personObj.getID();
        if (root->nodeKey > val) {
            if (!root->left) {
                root->left = new Node<T>(personObj);
            } else {
                addHelper(root->left, personObj);
            }
        } else {
            if (!root->right) {
                root->right = new Node<T>(val);
            } else {
                addHelper(root->right, val);
            }
        }
    }

    void printHelper(Node<T> *root) {
        if (!root) return;
        printHelper(root->left);
        cout<<root->nodeKey<<' ';
        printHelper(root->right);
    }

    int nodesCountHelper(Node<T> *root) {
        if (!root) return 0;
        else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
    }

    int heightHelper(Node<T> *root) {
        if (!root) return 0;
        else return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

    void printMaxPathHelper(Node<T> *root) {
        if (!root) return;
        cout<<root->nodeKey<<' ';
        if (heightHelper(root->left) > heightHelper(root->right)) {
            printMaxPathHelper(root->left);
        } else {
            printMaxPathHelper(root->right);
        }
    }

    bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
        if (!current) return false;
        if (current->nodeKey == value) {
            if (current->left == NULL || current->right == NULL) {
                Node<T>* temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                } else {
                    this->root = temp;
                }
            } else {
                Node<T>* validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                T temp = current->value;
                current->nodeKey = validSubs->nodeKey;
                validSubs->nodeKey = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

    public:
    void add(T val) {
        if (root) {
            this->addHelper(root, val);
        } else {
            root = new Node<T>(val);
        }
    }

    void print() {
        printHelper(this->root);
    }

    int nodesCount() {
        return nodesCountHelper(root);
    }

    int height() {
        return heightHelper(this->root);
    }

    void printMaxPath() {
        printMaxPathHelper(this->root);
    }
    
    Node<T>* getRoot(){
        return this->root;
    }
    
    void outputPreorderStudentToFile(Node<T>* node, string filename)
    {
        if (node == NULL)
            return;
        
        /* first PRINT data of node */
        ofstream myfile;
        if(node == this->root){myfile.open(filename);}
        else{myfile.open(filename, std::ios::app);}
        myfile << node->nodeKey << endl;
        myfile << node->value->getGPA() << endl;
        myfile << node->value->getMajor() << endl;
        myfile << node->value->getAdvisor() << endl;
        myfile.close();
        
        
        /* then recur on left subtree */
        outputPreorderStudentToFile(node->left, filename);
        
        /* now recur on right subtree */
        outputPreorderStudentToFile(node->right, filename);
    }
    
    void outputPreorderFacultyToFile(Node<T>* node, string filename)
    {
        if (node == NULL)
            return;
        
        /* first PRINT data of node */
        ofstream myfile;
        if(node == this->root){myfile.open(filename);}
        else{myfile.open(filename, std::ios::app);}
        myfile << node->nodeKey << endl;
        myfile << node->value->getDepartment() << endl;
        int numStudents = node->value->getStudents().size();
        for(int i = 0; i < numStudents; ++i){
            myfile << (node->value->getStudents())[i] << endl;
        }
        myfile.close();
        
        /* then recur on left subtree */
        outputPreorderFacultyToFile(node->left, filename);
        
        /* now recur on right subtree */
        outputPreorderFacultyToFile(node->right, filename);
    }
    
    bool deleteValue(T value) {
        return this->deleteValueHelper(NULL, this->root, value);
    }
};
int main(){
  return 0;
}
