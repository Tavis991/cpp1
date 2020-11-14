//
// Created by tuli on 07/11/2020.
//

#ifndef HW1_SETLL_H
#define HW1_SETLL_H
#include "Set.h"
#include "LLNode.h"

class SetLL {
public:
    SetLL(){
        head=NULL;
        curr=NULL;
    }
    void append(Set& set);
    void gotoNext() { if(curr->getNext()) curr = curr->getNext(); }
    bool hasNext() { if(curr->getNext()) { return true; } return false;}
    void gotoPrior();
    void gotoBeginning() { curr = head; }
    void gotoEnd() { while(hasNext()) gotoNext(); }
    void Destroy();
    void Print();
    bool isEmpty()  {if (head) { return false;} return true; }
    LLNode* getCurr();
    void Replace(Set& new_set);
    LLNode* getHead() { return head; }
    int delNext(LLNode* prev);
    void Decap(Set& new_set);
    LLNode* find(string name);
private:
    LLNode* head;
    LLNode* curr;
};


#endif //HW1_SETLL_H
