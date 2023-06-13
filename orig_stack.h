#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
  public:
    Stack();
    Stack(const T&);
    ~Stack();
    Stack<T>& operator=(const T&);
    int size();
    void push(T);
    T pop();
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
:current_size(-1),maximum_size(chunk_size),base(new T[chunk_size])
{
}

template<typename T>
Stack<T>::Stack(const T& s)
:maximum_size(s.maximum_size), base(new T[s.maximum_size])
{
  if(s.current_size>-1)
  {
    for(current_size=0; current_size<=s.current_size; current_size++)
      base[current_size]=s.base[current_size];
    current_size--;
  }
}

template<typename T>
Stack<T>::~Stack()
{
  delete [] base;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const T& s)
{
  delete [] base;
  maximum_size=s.maximum_size;
  base=new T[maximum_size];
  current_size=s.current_size;
  if(current_size>-1)
  {
    for(int x=0; x<=current_size; x++)
      base[x]=s.base[x];
  }
  return *this;
}

template<typename T>
void Stack<T>::push(T element)
{
  current_size++;
  if(current_size==maximum_size-1)
  {
    maximum_size+=chunk_size;
    T* new_buffer = new T[maximum_size];
    for(int x=0; x<current_size; x++)
      new_buffer[x]=base[x];
    delete [] base;
    base=new_buffer;
  }
  base[current_size]=element;
}

template<typename T>
T Stack<T>::pop()
{
  if(current_size<0)
    throw "Nothing to pop!";
  return base[current_size--];
}

template<typename T>
int Stack<T>::size()
{
  return current_size+1;
}

#endif
