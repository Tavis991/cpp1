//
// Created by tuli on 11/11/2020.
//

#include "LLNode.h"


void LLNode::setNext(LLNode *& new_node) {next=new_node;}
void LLNode::setData(Set &new_set) {data=new_set;}
void LLNode::Destroy(){ data.destroy(); next=NULL;}
LLNode *LLNode::getNext() {return next;}
