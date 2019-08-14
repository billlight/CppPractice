/*
 * doubleList_T.h
 *
 *  Created on: 2019Äê7ÔÂ16ÈÕ
 *      Author: yifan
 */

#ifndef DOUBLELIST_T_H
#define DOUBLELIST_T_H
#include <iostream>
#include "Iterator.h"
#include <assert.h>

template <class T>
class List{
	protected:
		class Node{
			public:
				T data;
				Node* next = NULL;
				Node* prev = NULL;
				Node(T val){data = val;}
				~Node(){if (next != NULL) {delete next;}}
		};
		Node* front;
		Node* rear;
		int lSize;

	public:
		class ListIterator: public Iterator<T>{
			Node * cur;
			bool direction;
			public:
				ListIterator(Node * ptr, bool fward) {
					cur = ptr;
					direction = fward;
				}
				bool hasNext() {
					return cur != NULL;
				}
				T next(){
					T val = cur->data;
					direction? cur = cur->next:cur = cur->prev;
					return val;
				}
				void remove(){}
		};
		Iterator<T> * iterator(bool direction) {
			return direction? new ListIterator( front, direction ):new ListIterator( rear, direction );
		}
		List() { front = rear = NULL; lSize = 0;}
		~List() { if(front != NULL) delete front;}
		int size() { return lSize;}
		bool empty() { return lSize < 1;}
		void showFward(bool direction);
		void showBward(bool direction);
		List<T> * add(T val, int pos);
		List<T> * addFront(T val);
		List<T> * addRear(T val);
		List<T> * addInside(T val, int pos);
		List<T> * removeFront();
		List<T> * removeRear();
		List<T> * removeInside(int pos);
		List<T> * remove(int pos);
		T data(int pos);
		void add10Items();
};

template <class T>
void List<T>::showFward(bool direction){
	printf("\n");
	if (empty()){return;}
	Iterator<T> * itr = iterator(direction);
	int i = 0;
	T v;
	while(itr->hasNext()){
		v = itr->next();
		printf("\t\t[%d] = %c\n", i++, v);
	}
	printf("\n");
}

template <class T>
List<T> *  List<T>::addFront(T val){
	Node* ptr = new Node(val);
	if(empty()){
		front = ptr;
		rear = ptr;
		lSize++;
		return this;
	}
	ptr->next = front;
	front->prev = ptr;
	front = ptr;
	lSize++;
	return this;
}

template <class T>
List<T> * List<T>::addRear(T val){
	Node* ptr = new Node(val);
	rear->next = ptr;
	ptr->prev = rear;
	rear = ptr;
	if(empty()){front = rear;}
	lSize++;
	return this;
}

template <class T>
List<T> * List<T>::addInside(T val,int pos){
	Node * ptr = new Node(val);
	Node * cur = front;
	for(int i = 1; i < pos; i++){
		cur = cur->next;
	}
	ptr->next = cur->next;
	cur->next->prev = ptr;
	ptr->prev = cur;
	cur->next = ptr;
	lSize++;
	return this;
}

template <class T>
List<T> * List<T>::add(T val, int pos){
	if (lSize < 1 || pos < 1){return addFront(val);}
	if (pos >= lSize){return addRear(val);}
	return addInside(val,pos);
}

template <class T>
List<T> * List<T>::removeFront(){
	Node * ptr = front->next;
	front->next = ptr->prev = NULL;
	delete front;
	front = ptr;
	lSize--;
	return this;
}

template <class T>
List<T> * List<T>::removeRear(){
	Node * ptr = rear->prev;
	ptr->next = rear->prev = NULL;
	delete rear;
	rear = ptr;
	lSize--;
	return this;
}

template <class T>
List<T> * List<T>::removeInside(int pos){
	Node * ptr = front;
	Node * cur = front;
	for(int i = 0; i < pos; i++){
		ptr = cur;
		cur = cur->next;
	}
	ptr->next = cur->next;
	cur->next->prev = ptr;
	cur->next = NULL;
	cur->prev = NULL;
	delete cur;
	lSize--;
	return this;
}

template <class T>
List<T> * List<T>::remove(int pos){
	if(empty()|| pos < 0 || pos >= lSize){return this;}
	if(lSize == 1){
		front = rear = NULL;
		return this;
	}
	if(pos == 0){return removeFront();}
	if(pos == (lSize-1)){return removeRear();}
	return removeInside(pos);
}

template <class T>
T List<T>::data(int pos){
	if(pos <= 0){return front->data;}
	if(pos >= lSize-1){return rear->data;}
	if(pos < lSize-1 && pos > 0){
		Node* ptr = front;
		for(int i = 0; i < pos; i++){
			ptr = ptr->next;
		}
		return ptr->data;
	}
	return (T)0;
}

#endif /* DOUBLELIST_T_H_ */
