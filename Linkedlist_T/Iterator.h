/*
 * Iterator.h
 *
 *  Created on: 2019��7��16��
 *      Author: yifan
 */
#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>

template<class T>
class Iterator {
    public:
    virtual bool hasNext();
    virtual T next();
    virtual void remove();
};

#endif /* ITERATOR_H */
