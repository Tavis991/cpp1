//
// Created by tuli on 07/11/2020.
//

#include "Set.h"
Set::Set()
:name("0"),size(0),elms(NULL)
{}

Set::Set(int *&elements, int count, string nom)
:name(nom){
//    cout<<"this is set init"<<endl;
//    cout<<"this is set initcount"<<count<<endl;
    int temp[count];
    int j=0;
    bool flg;
    for(int i=0;i<count;i++){
        flg=false;
        for (int k=0;k<j;k++){  //deleting duplicates
            if(elements[i]==temp[k]){flg=true; break;}
        }
        if (!flg){temp[j]=elements[i]; j++;}
        //cout<<elements[i];
    }
    elms=new int[j]; //allocating premenet array
    for(int i=0;i<j;i++){

        elms[i]=temp[i];
        //cout<<elms[i]<<"this is temp";
    }
    delete(elements);
    this->size=j;
    this->Sort();
}

void Set::Sort(){
    int i, j, key;
    for (i = 1; i < size; i++){
        key = elms[i];
        j = i - 1;
        while (j >= 0 && elms[j] > key){
            elms[j + 1] = elms[j];
            j = j - 1;
        }
        elms[j + 1] = key;
    }
//    for(int i=0;i<size;i++){
//       cout<<elms[i]<<"this is sorted set";
//    }
}
void  Set::printSet() const{
    cout<<'{';
    for(int i=0;i<size;i++){
        cout<<elms[i];
        if(i<size-1){cout<<',';}
    }
    cout<<'}';
}

void Set::destroy() { delete(elms); }
void Set::setName(string name){ this->name=name; }
string Set::getName() const { return (name); }
void Set::setElms(int*& elements) { this->elms=elements; }
int **Set::getElms() { return &elms; }
int Set::getSize() const { return size; }







