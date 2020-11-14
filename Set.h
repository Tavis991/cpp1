//
// Created by tuli on 07/11/2020.
//

#ifndef HW1_SET_H
#define HW1_SET_H
using namespace std;
#include <iostream>

class Set {
public:
    Set();
    Set(int *&elements, int count, string nom);
    void printSet() const;
    void Sort();
    void destroy();
    string getName() const;
    void setElms(int*& elements);
    int** getElms();
    void setName(string name);
    void setSize(int size) { this->size=size; }
    Set *getNext() const;
    int getSize() const;

private:
    int *elms;
    int size;
    string name;
};


#endif //HW1_SET_H
