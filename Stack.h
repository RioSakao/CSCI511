#ifndef STACK_H
#define STACK_H
#include <exception>
#include <iostream>
#include<algorithm>

using namespace std;

template<typename T>
class Stack
{
  public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();
    Stack<T>& operator=(const Stack<T>&);
    int size() const;
    void push(const T&);
    void pop();
    Stack<T>& top() const;
  private:
    static const int chunk_size;
    unsigned maximum_size;
    int current_size;
    T* base;
};

template<typename T>
const int Stack<T>::chunk_size=10;

template<typename T>
Stack<T>::Stack()
:current_size(-1),maximum_size(chunk_size),base((T*)malloc(sizeof(T)*chunk_size ))
        //base(new T[chunk_size])
{
}

template<typename T>
Stack<T>::Stack(const Stack<T> &s)
        :base((T*)malloc(sizeof(T)*s.maximum_size)),
        maximum_size(s.maximum_size)
{
  if(s.current_size>-1)
  {
    int success=0;
    try{
        for(current_size=0; current_size<=s.current_size; current_size++){
               success = current_size;
               new (&base[current_size]) T(s.base[current_size]);
        }
    } catch (...) {
            for(int i = success-1; i>=0; i--)
                    (base+i)->~T();
            free(base);
            throw; 
    }
    current_size--;
  }
}

template<typename T>
Stack<T>::~Stack()
{
  for(int i = current_size; i>=0; i--)
        (base+i)->~T();
  free(base);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &s)
{
  T *temp = (T*)malloc(sizeof(T)*s.maximum_size);
  if(s.current_size>-1)
  {
      int success=0;
      try {
            for(int x=0; x<=s.current_size; x++){
                    success = x;
                    new (&temp[x]) T(s.base[x]);
            }
      } catch(...) {
            for(int i = success-1; i>=0; i--)
                    (temp+i)->~T();
            free(temp);
            throw;
      }
  }
  for(int i = current_size; i>=0; i--)
        (base+i)->~T();
  free(base);
  base=temp;
  maximum_size=s.maximum_size;
  current_size=s.current_size;
  
  return *this;
}

template<typename T>
void Stack<T>::push(const T &element)
{
  current_size++;
  if(current_size==maximum_size)
  {//realllocation
    int success=0;
    maximum_size+=chunk_size;
    T* new_buffer = (T*)malloc(sizeof(T)*maximum_size);
    try {
        for(int x=0; x<current_size; x++) {
            success = x;
            new (&new_buffer[x]) T(base[x]);
        }
    } catch(...) {
        for(int i = success-1; i>=0; i--)
            (new_buffer+i)->~T();
        free(new_buffer);
        current_size--;
        throw;
    }
    free(base);
    base=new_buffer;
  }
  new (&base[current_size]) T(element);
  //base[current_size]=element;
}

template<typename T>
void Stack<T>::pop()
{
  if(current_size<-1)
    throw "Nothing to pop!";
  
  (base+(current_size))->~T(); //pop off an object at the last index
  current_size -= 1; //reduce size by 1
}

template<typename T>
Stack<T>& Stack<T>::top() const{
    if(current_size<-1)
        throw "The array is empty!";
    return &base[0];
}

template<typename T>
int Stack<T>::size() const
{
  return current_size+1;
}


#endif
