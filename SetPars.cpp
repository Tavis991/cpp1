//
// Created by tuli on 07/11/2020.
//

#include <cstdlib>
#include "SetPars.h"
SetPars::SetPars() {

}

string SetPars::parseName() {
    string temp;
    getline(cin,temp);
    cin>>t;
    if (t.size()>8) return "0";
    for (int i=0;i<t.size();i++) { if (! isupper(t[i]) ) { return "0"; } }
    return t;
}

string SetPars::parse2Name(){
    string temp;
    string inT;
    getline(cin,temp);
    cin>>t;
    if (t.size()>8) return "0";
    for (int i=0;i<t.size();i++) { if (! isupper(t[i]) ) { return "0"; } }
    cin>> inT;
    if (inT.size()>8) return "0";
    for (int i=0;i<inT.size();i++) { if (! isupper(inT[i]) ) { return "0"; } }
    t += inT;
    return t;
}

int SetPars::parseSet(int *& pointy) {
    string temp;
    int tempNUM;
    int count=0;
    cin.ignore();
    getline(cin,temp);
    int *arr= new int[(temp.size()/2)]; // i want this dynamical aloc, max size of legal arr
    pointy=arr; //assigning aloc to pointer

    if ((const char)temp[0]!='{') {return -1;} //initial conditions

    int i=1;
    if (temp.size()==2){
        if (temp[i]=='}'){ return 0;} else{return -1;}
    }  //empty set
    if (!isdigit(temp[i])){
        //must start w digit
        return 1;
    }
    for  (i=1;i<temp.size()-1;i++){ //parsing set string

            string tempINT;
            int j=0; //max digits in int
                while(temp[i]!=' ' && i<temp.size()-1) { //break tokenizing loop if ' '
                    if (isdigit(temp[i])){
                        tempINT += temp[i];
                        i++;
                             if ((++j)>9) { return -1; } //max digits in int
                     }
                    else { return -1; } //illegal input
                }
            stringstream tip(tempINT);
            tip>>tempNUM;
            *arr=tempNUM;
            arr++; count++;
            }

        if(temp[i-1]!='}'){return -1;}
        return count;
    }

