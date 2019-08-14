/*
 * BinarySearchTree.h
 *
 *  Created on: 2019Äê7ÔÂ24ÈÕ
 *      Author: yifan
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



template <class T>
class BST{
	static const int emptySlot = -9999991;
	static const int count = 10;
  private:
	class Node{
	  public:
		int data;
		Node * left;
		Node * right;
		Node(){data = emptySlot; left = NULL; right = NULL;}
		Node(T val){data = val; left = NULL; right = NULL;}
		~Node(){
			if(left != NULL) delete left;
			if(right != NULL) delete right;
		}
	};
	Node * root;
	//Recursively find the right place to add
	void insert(int v, Node * ptr){
		if(root == NULL){root = leaf(v); return;}
		if(v < ptr->data && ptr->left != NULL) insert(v, ptr->left);
		if(v < ptr->data && ptr->left == NULL) ptr->left = leaf(v);
		if(v >= ptr->data && ptr->right != NULL) insert(v, ptr->right);
		if(v >= ptr->data && ptr->right == NULL) ptr->right = leaf(v);
	}
	//Recursively find the right place to print out the entry
	void showPrivate(int index, Node * ptr){
		if(root == NULL || ptr == NULL) return;
		index += count;
		if(ptr->right != NULL){showPrivate(index, ptr->right);}
	    cout<<endl;
	    for (int i = count; i < index; i++)  cout<<" ";
	    cout<< ptr->data <<"\n";
		if(ptr->left != NULL){showPrivate(index, ptr->left);}
	}
	//Recursively find the entry with the desired value
	Node * search(int key, Node * ptr){
		if(root == NULL || ptr == NULL) return NULL;
		if(ptr->data == key) return ptr;
		if(key < ptr->data) return search(key, ptr->left);
		return search(key, ptr->right);
	}
	//Recursively find the smallest value in the subtree
	int findSmallest(Node * ptr){
		if ( root == NULL){return emptySlot;}
		if(ptr->left != NULL){return findSmallest(ptr->left);}
		return ptr->data;
	}
	//Recursively find the entry with the desired value to delete
	void removePrivate(int key, Node * ptr){
		if(root == NULL || ptr == NULL) return;
		if(root->data == key){removeRootMatch();}
		else{
			if(key < ptr->data && ptr->left != NULL){
				ptr->left->data == key ? removeMatch(ptr, ptr->left, true):removePrivate(key, ptr->left);
			}
			else{
				ptr->right->data == key ? removeMatch(ptr, ptr->right, false):removePrivate(key, ptr->right);
			}
		}

	}
	//Remove the root in three cases
	void removeRootMatch(){
		if(root == NULL) return;
		if(root != NULL){
			Node * toDelete = root;
			int smallest;
			//case 0-0 children
			if(root->left == NULL && root->right == NULL){
				root = NULL;
				delete toDelete;
			}//case 0-1 children
			else if(root->left == NULL && root->right != NULL){
				root = root->right;
				toDelete->right = NULL;
				delete toDelete;
			}//case 1-0 children
			else if(root->left != NULL && root->right == NULL){
				root = root->left;
				toDelete->left = NULL;
				delete toDelete;
			}//case 1-1 children
			else{
				smallest = findSmallest(root->right);
				removePrivate(smallest, root);
				root->data = smallest;
			}
		}
	}
	//
	void removeMatch(Node * parent, Node * match, bool left){
		if(root == NULL) return;
		if( root != NULL){
			Node * toDelete;
			int smallest;
			//case 0-0 children
			if (match->left == NULL && match->right == NULL){
				toDelete = match;
				left ? parent->left = NULL : parent->right = NULL ;
				delete toDelete;
			}//case 0-1 children
			else if(match->left == NULL && match->right != NULL){
				left ? parent->left = match->right : parent->right = match->right ;
				match->right = NULL;
				toDelete = match;
				delete toDelete;
			}//case 1-0 children
			else if(match->left != NULL && match->right == NULL){
				left ? parent->left = match->left : parent->right = match->left ;
				match->left = NULL;
				toDelete = match;
				delete toDelete;
			}//case 1-1 children
			else{
				smallest = findSmallest(match->right);
				removePrivate(smallest, match);
				match->data = smallest;
			}
		}
	}
	/*
	void removePrivate(int key, Node * ptr){
		if(root == NULL || ptr == NULL) return;
		if(root->data == key) removeRootMatch();
		if(root->data != key && key < ptr->data && ptr->left != NULL){
			ptr->left->data == key ? removeMatch(ptr, ptr->left, true):removePrivate(key, ptr->left);
		}
		if(root->data != key && key >= ptr->data && ptr->right != NULL){
			ptr->right->data == key ? removeMatch(ptr, ptr->right, false):removePrivate(key, ptr->right);
		}
		return;
	}
*/
  public:
	BST(){root = NULL;}
	~BST(){delete root;}
	Node * leaf(int v){Node * nn = new Node(v); return nn;}
	void add(int v){insert(v, root);}
	void show(){showPrivate(0, root);}
	void find(int val){printf("%s", search( val, root) != NULL? "Found" : "Not found");}
	void remove(int val){removePrivate( val, root);}
};





#endif /* BINARYSEARCHTREE_H */
