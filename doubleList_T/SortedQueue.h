/*
 * SortedQueue.h
 *
 *  Created on: 2019/7/18
 *      Author: yifan
 */

#ifndef SORTEDQUEUE_H_
#define SORTEDQUEUE_H_
#include "doubleList_T.h"
#include "Iterator.h"
#include "Queue.h"

template <class T>
class SQueue: protected Queue<T>{
   public:
	SQueue():Queue<T>(){}
	SQueue* enque(T val){
		if (List<T>::empty()){Queue<T>::enque(val); return this;}
		Iterator<T> * itr = List<T>::iterator(true);
		T v1;
		int i = 0;
		while(itr->hasNext()){
			v1 = itr->next();
			if (compare(v1,val)){break;}//v1 > val
			i++;
		}
		List<T>::add(val, i);
		return this;
	}
	SQueue* deque(){
		Queue<T>::deque();
		return this;
	}
	T front(){return Queue<T>::front();}

	void show(){List<T>::showFward(true);}
	bool compare(T val1, T val2){
		return val1 > val2;
	}
};





#endif /* SORTEDQUEUE_H_ */
