/*
 * Stack.h
 *
 *  Created on: 2019Äê7ÔÂ17ÈÕ
 *      Author: yifan
 */

#ifndef STACK_H_
#define STACK_H_
#include "doubleList_T.h"
#include "Iterator.h"

template <class T>
class Stack: protected List<T>{
   public:
	Stack():List<T>(){}
	Stack* push(T val){
		List<T>::add(val, 0);
		return this;
	}
	Stack* pop(){
		List<T>::remove(0);
		return this;
	}
	T top(){return List<T>::data(0);}
};





#endif /* STACK_H_ */
