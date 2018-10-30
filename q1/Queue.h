//
//  Queue.hpp
//  Queue
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class Queue
{
public:
    Queue();
    Queue(int);
    void enqueue(T);
    void dequeue();
    T peek();
    int getQuantity();
    
private:
    int quantity;
    std::stack<T> instack;
    std::stack<T> outstack;
    void inToOut();
    void outToIn();
};

template<typename T>
Queue<T>::Queue():quantity(0)
{
}

template<typename T>
void Queue<T>::inToOut(){
    while(!this->instack.empty()){
        this->outstack.push(this->instack.top());
        this->instack.pop();
    }
}

template<typename T>
void Queue<T>::outToIn(){
    while(!this->outstack.empty()){
        this->instack.push(this->outstack.top());
        this->outstack.pop();
    }
}

template<typename T>
int Queue<T>::getQuantity()
{
	return this->quantity;
}

template<typename T>
T Queue<T>::peek(){
    if(this->outstack.empty()){
        this->inToOut();
    }
    return this->outstack.top();
}

template<typename T>
void Queue<T>::enqueue(T element){
    if(this->instack.empty()){
        this->outToIn();
    }
    this->instack.push(element);
    this->quantity++;
}

template<typename T>
void Queue<T>::dequeue(){
    if(this->outstack.empty()){
        this->inToOut();
    }
    this->outstack.pop();
    this->quantity--;
}

#endif /* Queue_hpp */
