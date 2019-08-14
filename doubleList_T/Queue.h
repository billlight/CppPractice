/*
 * Queue.h
 *
 *  Created on: 2019Äê7ÔÂ17ÈÕ
 *      Author: yifan
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "doubleList_T.h"
#include "Iterator.h"

template <class T>
class Queue: protected List<T>{
   public:
	Queue():List<T>(){}
	Queue* enque(T val){
		List<T>::add(val, List<T>::size()-1);
		return this;
	}
	Queue* deque(){
		List<T>::remove(0);
		return this;
	}
	T front(){return List<T>::data(0);}
};





#endif /* QUEUE_H_ */
