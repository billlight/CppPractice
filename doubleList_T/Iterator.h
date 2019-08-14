/*
 * Iterator.h
 *
 *  Created on: 2019Äê7ÔÂ16ÈÕ
 *      Author: yifan
 */
#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>

template<class T>
class Iterator {
    public:
    virtual bool hasNext() = 0 ;
    virtual T next() = 0;
    virtual void remove() = 0;
};

#endif /* ITERATOR_H */

