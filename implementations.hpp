#include "prototypes.hpp"

//CONSTRUCTOR
template <typename T>
MyQueue<T>::MyQueue()
{
    q_ptr = nullptr;
    q_size = 0;
    q_cap = 0;
    q_index = 0;
}

//ALLOCATOR
template <typename T>
void MyQueue<T>::allocator()
{
    q_cap = 2;
    q_ptr = new T [q_cap];
}

//ENQUE  --->  PUSH 
template <typename T>
void MyQueue<T>::enqueue(T val)
{
    if(!q_ptr)
    {
        allocator();
    }

    if(q_index + q_size + 1 > q_cap)
    {
        if(q_index >= q_cap / 2)
        {
            for(int i = q_index, k = 0; k < q_size; ++i , ++k)
            {
                q_ptr[k] = q_ptr[i];
            }
            q_ptr[q_size] = val;
        }

        else
        {
            q_cap *= 2;
            T* ptr1 = new T[q_cap];
            for(int i = q_index , k = 0; k < q_size; ++i , ++k)
            {
                ptr1[k] = q_ptr[i];
            }
            ptr1[q_size] = val;
            delete[] q_ptr;
            q_ptr = ptr1;
            ptr1 = nullptr;
            q_index = 0;
        }
    }

    else
    {
        q_ptr[q_index + q_size] = val;
    }

    q_size++;
}

//DEQUEUE  --->  POP
template <typename T>
void MyQueue<T>::dequeue()
{
    if(q_size)
    {
        q_index ++;
        q_size --;
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        return;
    }
}

//PRINT
template <typename T>
void MyQueue<T>::print()
{
    if(q_ptr)
    {
        for(int i = q_index; i < q_size + q_index; ++i)
        {
            std::cout << q_ptr[i]  << " " ;
        }
        std::cout << std::endl;
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        return;
    }
}

//DESTRUCTOR
template <typename T>
MyQueue<T>::~MyQueue()
{
    if(q_ptr)
    {
        delete[] q_ptr;
        q_size = 0;
        q_cap = 0;
        q_index = 0;
    }
}

//SIZE
template <typename T>
size_t MyQueue<T>::size()
{
    return q_size;
}

//ISEMPTY
template <typename T>
bool MyQueue<T>::isEmpty()
{
    return q_size == 0;
}

//FRONT
template <typename T>
T& MyQueue<T>::front()
{
    if(q_ptr)
    {
        return q_ptr[q_index];
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        exit(0);
    }
}

//REAR
template <typename T>
T& MyQueue<T>::rear()
{
    if(q_ptr)
    {
        return q_ptr[q_index + q_size - 1];
    }

    else
    {
        std::cout << "unvalid operation: " << std::endl;
        exit(0);
    }
}
