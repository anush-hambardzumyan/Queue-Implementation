#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

#include <iostream>

template <typename T>
class MyQueue
{
    private:
    T* q_ptr;
    size_t q_cap;
    size_t q_size;
    size_t q_index;

    public:
    MyQueue();
    void allocator();
    void print();
    void reallocator();
    void enqueue(T);
    void dequeue();
    T& front();
    T& rear();
    size_t size();
    bool isEmpty();
    ~MyQueue();
};


#include "implementations.hpp"

#endif