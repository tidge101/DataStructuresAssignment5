#include <stddef.h>

template <typename T>
struct Node{
    int key;
    T elem;
    Node* left;
    Node* right;
    Node* parent;
}

class BST{
private:
    Node* root;
public:
    BST(){root = NULL;}
    
    ~BST(){}
    
    void insert(int k, Node* newNode){
        if(k< newNode->key)
        {
            if(newNode->left!=NULL)
                insert(k, newNode->left);
            else
            {
                newNode->left=new node;
                newNode->left->key=k;
                newNode->left->left=NULL;    //Sets the left child of the child node to null
                newNode->left->right=NULL;   //Sets the right child of the child node to null
            }
        }
        else if(k>=newNode->key)
        {
            if(newNode->right!=NULL)
                insert(k, newNode->right);
            else
            {
                newNode->right=new node;
                newNode->right->key=k;
                newNode->right->left=NULL;  //Sets the left child of the child node to null
                newNode->right->right=NULL; //Sets the right child of the child node to null
            }
        }	
    }
    
    Node* search(int k, Node* leaf){
        if(leaf!=NULL)
        {
            if(k==leaf->key)
                return leaf;
            if(k<leaf->key)
                return search(k, leaf->left);
            else
                return search(k, leaf->right);
        }
        else return NULL;
    }
    
    
}
