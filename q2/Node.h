//
//  Node.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __LinkedList__Node__
#define __LinkedList__Node__

#include <iostream>

template <typename T>
class Node
{
private:
    T value;
    Node<T>* next;
    Node<T>* prev;
    
public:
    Node();
    
    Node( T );
    
    Node( T, Node*, Node* );
    
    T getValue();
    
    void setValue(T val);
    
    Node* getNext();
    
    void setNext(Node*);
	
	Node* getPrevious();
	
	void setPrevious(Node*);

    void linkMeAfter(Node*);

    void linkMeBefore(Node*);

    void unlinkMe();

};

template<typename T>
Node<T>::Node(void):
next(nullptr), prev(nullptr) {}

template<typename T>
Node<T>::Node(T val):
value(val), next(nullptr), prev(nullptr) {}

template<typename T>
T Node<T>::getValue(void)
{
    return this->value;
}

template<typename T>
Node<T>* Node<T>::getNext(void)
{
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T>* n)
{
    this->next = n;
}

template<typename T>
Node<T>* Node<T>::getPrevious(void)
{
	return this->prev;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* p)
{
	this->prev = p;
}

template<typename T>
void Node<T>::linkMeAfter(Node<T>* nPrev)
{
	if(nPrev == nullptr){
        std::cerr << "Erro! Ponteiro nulo!" << std::endl;
        return;
    };
    Node<T>* nNext = nPrev->getNext();
    if(nNext == nullptr){
        std::cerr << "Erro! Ponteiro nulo!" << std::endl;
        return;
    };
    this->prev = nPrev;
    this->next = nNext;
    this->prev->setNext(this);
    this->next->setPrevious(this);
}

template<typename T>
void Node<T>::linkMeBefore(Node<T>* nNext)
{
    if(nNext == nullptr){
        std::cerr << "Erro! Ponteiro nulo!" << std::endl;
        return;
    };
    Node<T>* nPrev = nNext->getPrevious();
    if(nPrev == nullptr){
        std::cerr << "Erro! Ponteiro nulo!" << std::endl;
        return;
    };
    this->prev = nPrev;
    this->next = nNext;
    this->prev->setNext(this);
    this->next->setPrevious(this);
}

template<typename T>
void Node<T>::unlinkMe()
{
    this->prev->setNext(this->next);
    this->next->setPrevious(this->prev);
	this->prev = nullptr;
    this->next = nullptr;
}

#endif /* defined(__LinkedList__Node__) */
