//
// Created by tuli on 11/11/2020.
//

#ifndef HW1_LLNODE_H
#define HW1_LLNODE_H
#include "Set.h"

class LLNode {

public:
    LLNode()
    :next(NULL){}
    LLNode(Set& set)
    :next(NULL),data(set){}
    LLNode* getNext();
    void nullify() { next=NULL; }
    void printNod(){ data.printSet(); }
    void setNext(LLNode*& new_node);
    void setData(Set& new_set);
    Set* getData() {return &data;};
    void Destroy();

private:
    LLNode* next;
    Set data;
};


#endif //HW1_LLNODE_H
