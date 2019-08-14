/*
 * List_temp.h
 *
 *  Created on: 2019Äê7ÔÂ16ÈÕ
 *      Author: yifan
 */

#ifndef LIST_TEMP_H
#define LIST_TEMP_H
#include <iostream>
#include "Iterator.h"

template <class T>
class List {
	protected:
		class Node{
			public:
				T data;
				Node * next;
				Node(T value){ data = value; next = NULL;}
				~Node(){if( next != NULL) delete next;}
		};
		Node * front;
		Node * rear;
		int lSize;
	public:
		class ListIterator: public Iterator<T>{
			Node * cur;
			public:
				ListIterator( Node * ptr ) { cur = ptr; }
				bool hasNext() { return cur->next != NULL;}
				T next(){
					T val = cur->data;
					cur = cur->next;
					return val;
				}
				void remove() {}
		};
		List() { front = rear = NULL; lSize = 0;}
		~List() { if(front != NULL) delete front;}
		int size() { return lSize;}
		bool empty() { return lSize < 1;}
		List<T>* addFront(T val);
		List<T>* addRear(T val);
		List<T>* add(T val, int pos);
		void show();
		List<T>* removeFront();
		List<T>* removeRear();
		List<T>* remove(int pos);
		T data(int pos);
		Iterator<T> * iterator() { return new ListIterator( front ); }
};

template <class T>
List<T>* List<T>:: addFront(T val){
	Node* nn = new Node(val);
	nn->next = front;
	front = nn;
	if(empty()){rear = front;}
	lSize++;
	return this;
}

template <class T>
List<T>* List<T>:: addRear(T val){
	Node* nn = new Node(val);
	if ( empty() ) front = rear = nn;
	else {
		rear->next = nn;
		rear = nn;
	}
	lSize++;
	return this;
}

template <class T>
List<T>* List<T>:: add(T val, int pos) {
    if (lSize < 1 || pos < 1)
	return addFront(val);
    if (pos >= lSize) return addRear(val);

    Node * cur = front, * nn = new Node(val);

    for(int i = 0; i < pos-1; i++)  cur = cur->next;

    nn->next = cur->next;
    cur->next = nn;
    lSize++;
    return this;
}

template <class T>
void List<T>:: show(){
	Iterator<char> * itr = iterator();
    int i = 0;
    T v;
    while (itr->hasNext()) {
	v = itr->next();
	printf("\t\t[%d] = %c\n", i++, v);
    }
    printf("\n");
}

template <class T>
List<T>* List<T>::removeFront() {
	Node * ptr = front->next;
	front->next = NULL;
	delete front;
	front = ptr;
    lSize--;
    return this;
}

template <class T>
List<T>* List<T>::removeRear() {
    Node * ptr = front;
    while(ptr->next != rear) ptr = ptr->next;
    ptr->next = NULL;
    delete rear;
    rear = ptr;
    lSize--;
    return this;
}

template <class T>
List<T>* List<T>::remove(int pos) {
    if(empty()|| pos < 0 || pos >= lSize){return this;}
    if(pos == 0)         return removeFront();
    if(pos == (lSize-1)) return  removeRear();

    Node * prev = front, * toDelete = front->next;
    for(int i = 1; i < pos; i++) {
        prev = toDelete; toDelete = toDelete->next;
    }

    prev->next = toDelete->next;
    toDelete->next = NULL;
    delete toDelete;;
    lSize--;
    return this;
}

template <class T>
T List<T>::data(int pos){
    T v;
    if (empty()){return v;}
    if (pos <= 0){return front->data;}
    if(pos >= lSize-1){return rear->data;}
    Iterator<char> * itr = iterator();
    int i = 0;
    while (itr->hasNext()) {
    	v = itr->next();
    	//printf("\t\t[%d] = %c\n", i++, v);
    	if (i == pos){
    		return v;
    	}
    	i++;
    }
    return ' ';
}

#endif /* LIST_TEMP_H_ */
