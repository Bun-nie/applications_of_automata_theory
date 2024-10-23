/*
Design a DFA to accept all the strings over the alphabet {a,b},
having even number of a's and odd number of b's
*/
#include<iostream>
using namespace std;

typedef struct Node{
    string name;
    bool isFinal = 0;
    struct Node *aInput  = NULL;
    struct Node *bInput = NULL;
} State;

class evenaOddb {

    State q1,q2,q3,q4;

    public:
    evenaOddb(){
        q1.name = "q1";
        q2.name = "q2";
        q3.name = "q3";
        q4.name = "q4";
      

        q2.isFinal = 1;
        
        //q1 state
        q1.aInput = &q3;
        q1.bInput = &q2;
        
        //q2 state
        q2.aInput = &q4;
        q2.bInput = &q1;

        //q3 state
        q3.aInput = &q1;
        q3.bInput = &q4;

        //q4 state
        q4.aInput = &q2;
        q4.bInput = &q3;
   

    }
    //returns whether the string is in final state
    //Along with that it prints the transitions
    bool determine(string inputString) {
        State *presentState = &q1;
        cout<<presentState->name;
        for(char c:inputString){
            if(c == 'a'){
                presentState = presentState->aInput;
                cout<<"-->"<<presentState->name;
            }else{
                presentState = presentState->bInput;
                cout<<"-->"<<presentState->name;
            }
        }
        cout<<'\n';
        return presentState->isFinal;
    }

};


int main(){
    evenaOddb fsm;
    string ip;
    do {
        cout<<"[Enter 'exit' to exit loop]"<<endl<<"Enter String: ";
        cin>>ip;
        bool accepted = fsm.determine(ip);
        if(accepted) cout<<"Accepted"<<endl;
        else cout<<"Not Accepted"<<endl;
    } while (ip != "exit");
    
    cout<<"Program Terminated..."<<endl;
    return 0;
}