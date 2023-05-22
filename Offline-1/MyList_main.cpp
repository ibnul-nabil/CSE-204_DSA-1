#include <bits/stdc++.h>

//select the hearderfile to operate in array or linked list mode 

//#include "Arr.h"
#include "LL.h"

using namespace std;

int main(void){

    int X , K;
    int Q;


    ifstream in;
    in.open("list_input.txt");

    ofstream out;
    out.open("list_output.txt");

    in >> X  >> K;

    //MyList<int> m(K,X);
    MyList<int> m;
   
    int z;
    for (int i=0;i<X;i++){
        in>> z;
        m.pushBack(z);
    }


    in >>Q;

    m.setToPos(X/2);
    out << m.print();
    while(Q--){
        int F , P;
        in >> F  >> P;
        if (F==1){

            out << m.print()<< m.size() << "\n";
        }
        else if(F==2){
            m.push(P);
            
            out << m.print() << "-1\n";
        }
        else if(F==3){
            m.pushBack(P);
            
            out << m.print() << "-1\n";
            
        }
        else if(F==4){
            int a=m.erase();
            
            out << m.print() << a <<"\n";
            
        }
        else if(F==5){
            m.setToBegin();
            
            out << m.print() << "-1\n";
            
        }
        else if(F==6){
            m.setToEnd();
            
            out << m.print() << "-1\n";
            
        }
        else if(F==7){
            m.prev();
            
            out << m.print() << "-1\n";
            
        }
        else if(F==8){
            m.next();
            
            out << m.print() << "-1\n";
            
        }
        else if(F==9){
            int a=m.currPos();
            
            out << m.print() << a <<"\n";
            
        }
        else if(F==10){
            m.setToPos(P);
            
            out << m.print() << "-1\n";
            
        }
        else if(F==11){
            int a=m.getValue();
            
            out << m.print() << a <<"\n";
            
        }
        else if(F==12){
            int a=m.find(P);
          
            out << m.print() <<a <<"\n";
            
        }
        else{
            m.clear();

            out << m.print() << "-1\n";
        }
        


    }

    in.close();
    out.close();

    return 0;
}