//
// Created by tuli on 07/11/2020.
//


#include "SetCalc.h"
SetCalc::SetCalc()
:NAMERR("ERROR:does not exist"),SIZERR("ERROR:group has more than 10 elements"),INPERR("ERROR:input error"),CMDRR("ERROR: invalid command, type 0 for exit")
{size=0;

}
inline void clearC(){   cout << string( 20, '\n' );}

int SetCalc::run() {
    cout << "Set Calculator" << endl;
    unsigned char cmd=0;
    cin>>cmd;
    if(!isdigit(cmd)){
        cerr << CMDRR;
        return 1;
    }
    cmd=cmd-'0';
    switch(cmd){
        case(1): //add
            cout <<"pressed 1"<<endl;
            if(setAdd()){return 1;}

            SetLINKED.Print();
            cout<<"this is calc add function"<<endl;
            return 1;
        case(2):
            setDel();
            cout <<"pressed 2";
            return 2;
        case(3):
            clearC();
            cout <<"pressed 3"<<endl;
            if(setUnion()){return 1;}
            return 2;

        case(4):
            clearC();
            cout <<"pressed 3"<<endl;
            if(setIntersect()){ return 1; }
            return 4;
        case(5):
            clearC();
            cout <<"pressed 3"<<endl;
            if(powerSet()){ return 1; }
            return 5;
        case(6):
            if(setPrint()){return 1;}
            return 1;
        case(0):
            cout <<"pressed 0";
            if(SetLINKED.isEmpty()) return 1;
            SetLINKED.Destroy();
            return 0;
        default:
            cerr << CMDRR;
            return 1;
    }
return 1;
}

int SetCalc::setAdd() {
    clearC();
    int elmtSIZE;
    string nom;
    int *elmts=new int;  //pointer problems here FIXED:))
    nom = parsi.parseName();
    if ((nom == "0")) {
        cerr << INPERR;
        return 1;
    }
    //cout << nom;
    elmtSIZE = parsi.parseSet(elmts);
    cout<<"this is calc pars count"<<elmtSIZE<<endl;
    if (elmtSIZE == -1) { cerr << INPERR; return 1; }
    //for (int i=0;i<elmtSIZE;i++) {cout << elmts[i]<<endl; }//debug print
    Set *a = new Set(elmts, elmtSIZE, nom);
   // a->printSet();
    cout<<"this is calc";
    if ( SetLINKED.find(nom) ) { SetLINKED.Replace(*a) ;
        return 0; }
    SetLINKED.append(*a);
    delete (a);
    return 0;
}

int const SetCalc::setPrint() {
    string nom = parsi.parseName();
    if ((nom == "0")) {
        cerr << INPERR;
        return 1;
    }
    LLNode* temp =(SetLINKED.find(nom));
    if (temp) { temp->printNod(); return 0; }
    else { return 1; }
}

int SetCalc::setIntersect() {
    clearC();
    string nom1;
    string nom2;
    string nomNew;
    nom1 = parsi.parseName();
    if ((nom1 == "0")) {cerr << INPERR; return 1;}
    nom2 = parsi.parseName();
    if ((nom2 == "0")) {cerr << INPERR; return 1;}
    nomNew = parsi.parseName();
    if ((nomNew == "0")) {cerr << INPERR; return 1;}
     Set* bit1 = SetLINKED.find(nom1)->getData();
     Set* bit2 = SetLINKED.find(nom2)->getData();
    int count = max(bit1->getSize(),bit2->getSize());
    int * temps = new int[count];
    for (int i=0; i<bit1->getSize(); i++){
        for (int j=0; j<bit2->getSize(); j++){
            if (bit1->getElms()[i] == bit2->getElms()[j]){

            }
        }
    }

    return 0;

}

int SetCalc::setDel(){
    clearC();
    string nom;
    nom = parsi.parseName();
    if (nom == "0") { cerr << INPERR; return 1; }
    LLNode* tmp = ( SetLINKED.find(nom) ) ;
    if (tmp) { SetLINKED.delNext(tmp); }
    return 0;
}


int SetCalc::setUnion() {
    clearC();
    string nom1;
    string nom2;
    string nomNew;
    nom1 = parsi.parseName();
    if ((nom1 == "0")) {cerr << INPERR; return 1;}
    nom2 = parsi.parseName();
    if ((nom2 == "0")) {cerr << INPERR; return 1;}
    nomNew = parsi.parseName();
    if ((nomNew == "0")) {cerr << INPERR; return 1;}

    Set* bit1 = SetLINKED.find(nom1)->getData();
    Set* bit2 = SetLINKED.find(nom2)->getData();
    int * temps = new int[bit1->getSize()+bit2->getSize()];
    for ( int i=0; i<bit1->getSize(); i++ ){
        *temps=*bit1->getElms()[i];  temps++;
    }
    for ( int i=0; i<bit2->getSize(); i++ ){
        *temps=*bit2->getElms()[i];  temps++;
    }
    Set* unii = new Set (temps, bit2->getSize()+bit1->getSize(), nomNew);
    SetLINKED.append(*unii);
    return 0;
}

void SetCalc::Destroy() {
}

int SetCalc::powerSet(){
    clearC();
    string nom;
    nom = parsi.parseName();
    if((nom == "0")) { cerr << INPERR; return 1; }
    LLNode* tmp = SetLINKED.find(nom);
    if (tmp){
    Set *pow = new Set[2 ^ tmp->getData()->getSize()];

    }
    return 0;
}

int SetCalc::powerSetHelper(){

}
