//
// Created by tuli on 07/11/2020.
//
#include "Set.h"
#include "SetLL.h"
#include "LLNode.h"
void SetLL::append(Set *new_set) { /* 1. allocate node */
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

void SetLL::Replace(Set*& new_set){
    curr->Destroy();
    curr->setData(new_set);
}
//void SetLL::Decap(Set*& new_set){
//    head->Destroy();
//    head->setData(new_set);
//}
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
    if(isEmpty()) return;
    gotoBeginning();
    do { curr->printNod(); }
    while (!gotoNext());
}

LLNode * SetLL::find(string name) {
    if (isEmpty()) return NULL;
    gotoBeginning();
//    if(head->getData()->getName()==name){
//        return head;
//    }
    do {if (curr->getData()->getName()==name) { return curr; } }
    while(!gotoNext());
    return NULL;
}

int SetLL::del(LLNode* del) {
    if ( del == head ) { LLNode* tmp = del->getNext();
    head->Destroy(); head=tmp;  return 0; }
    else if ( del->getNext() ){
        LLNode* tmp = del->getNext();
        gotoPrior();
        curr->getNext()->Destroy();
        curr->setNext(tmp);
        return 0;
    }
    gotoPrior();
    curr->getNext()->Destroy();
    curr->nullify();
    return 0;
}

void SetLL::gotoPrior() {
    LLNode* temp = curr;
    gotoBeginning();
    while (curr->getNext() != temp) { gotoNext(); }
}

//void SetLL::gotoPrior() {gotoBeginning(); while(curr->getNext()!=)
//
//}


