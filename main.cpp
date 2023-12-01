#include "prototypes.hpp"

int main()
{
    MyQueue<int> qyu;
    qyu.enqueue(5);
    qyu.enqueue(10);
    qyu.enqueue(11);
    qyu.print();
    qyu.dequeue();
    qyu.print();
}