#include <iostream>

using namespace std;

template <typename T>
class TreeNode{
	T* data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

	TreeNode(T d){
		self->data = d;	
	}
};

template <typename T>
class BST{

	BST(){
		cout << "BST created!" << endl;
	}

	~BST(){
		cout << "BST destroyed" << endl;
	}

	bool find(T key){
		TreeNode* curr = root;
		while(curr != NULL){
			if(curr->data = key){return true;}
			else if(key < curr->data){curr = curr->left;}
			else{curr = curr->right;}
		}
		return false;
	}

	void insert(T entry){
		TreeNode* newNode = TreeNode<T>(entry);
		TreeNode* curr = root;
		while(curr != NULL){
			if(curr->data > entry){curr = curr->left;}
			else{curr = curr->right;}
		}
		if(entry < curr->parent->data){curr->parent->left = newNode;}
		else{curr->parent->right = newNode;}
	}

	TreeNode getSuccessor(TreeNode* d){
		TreeNode* sp = d; // successor parent
		TreeNode* successor = d; // should be leftmost of right child
		TreeNode* curr = d->right;

		while(curr != NULL){
			sp = succesor;
			successor = curr;
			curr = curr->left;
		}
		
		if(successor != d->right){
			sp->left = successor->right;
			successor->right = d->right
		}

		return successor;
	}

	deleteTreeNode(int key){
		if(root = ){

		}
		TreeNode* curr = root;
		TreeNode* parent = root;
		
		bool isLeft = true;

		while(curr->data != key){
			parent = curr;
			
			if(key < curr->data){
				curr = curr->left;
				isLeft = true;
			}
			else{
				curr = curr->right;
				isLeft = false;	
			}
			
			if(curr == NULL){cout << "Node not found!" << endl;}
		}		
	}
};
