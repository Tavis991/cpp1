//
// Created by tuli on 07/11/2020.
//
#include "Set.h"
#include "SetLL.h"
#include "LLNode.h"
void SetLL::append(Set &new_set) { /* 1. allocate node */
//    cout<<"this is append"<<endl;
//    new_set->printSet();
    LLNode *newNode = new LLNode(new_set);
    if (isEmpty()) { head = newNode; }
    else {
     gotoEnd();
    curr->setNext(newNode);
    curr=newNode;
    cout<<"this is append"<<endl;
    }

}

LLNode* SetLL::getCurr(){ return curr;}

void SetLL::Replace(Set& new_set){
    curr->getNext()->Destroy();
    curr->getNext()->setData(new_set);
}
void SetLL::Decap(Set& new_set){
    head->Destroy();
    head->setData(new_set);
}
void SetLL::Destroy() {
    gotoBeginning();
    LLNode* temp;
    head->Destroy();
    delete(head);
    while(curr->getNext()){
        temp = curr->getNext();
        curr->Destroy();
        delete(curr);
        curr=temp;
    }
}

void SetLL::Print() {
    gotoBeginning();
    curr->printNod();
    if ( !hasNext() ) return;
    while(hasNext()){
        gotoNext();
        curr->printNod();
    }
    curr->printNod();
}

LLNode * SetLL::find(string name) {
    if (isEmpty()) return NULL;
    gotoBeginning();
    if(head->getData()->getName()==name){
        return head;
    }
    while(hasNext()) { if (curr->getData()->getName()==name) { return curr; } }
    return NULL;
}

//int SetLL::delNext(LLNode* prev) {
//    if ( prev == head ) { head = NULL; return 0; }
//    else if (!(hasNext() && prev->getNext()hasNext())) { curr->getNext()->Destroy(); curr->nullify(); return 0;}
//    LLNode* tmp = prev->getNext()->getNext();
//    prev->getNext()->Destroy();
//    prev->setNext(tmp);
//    return 0;
//}

void SetLL::gotoPrior() {
    LLNode* temp = curr;
    gotoBeginning();
    while (curr->getNext() != temp) { gotoNext(); }
}

//void SetLL::gotoPrior() {gotoBeginning(); while(curr->getNext()!=)
//
//}


