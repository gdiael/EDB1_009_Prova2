//
//  LinkedList.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

#include "Node.h"
#include <string>

typedef enum {
    OK ,                // 0
    HeadNull,           // 1
    TailNull,           // 2
    HeadPrevious,       // ...
    HeadNextNull,
    TailNext,
    TailPreviousNull,
    HeadTail,
    IncorrectLink
} ListStatus ;

class LinkedList {
private:
    Node<std::string>* head;
    Node<std::string>* tail;
    int quantity;
    
public:
    LinkedList(void);
    ~LinkedList(void);

    Node<std::string>* getHead(void);
    Node<std::string>* getTail(void);
    
    bool insertEnd(std::string);

    ListStatus checkConsistency(void);
    bool isOrdered();

    void sort();
    
    void print(void);
    
    bool isEmpty(void);
    int getQuantity(void);
};

#endif /* defined(__LinkedList__LinkedList__) */
