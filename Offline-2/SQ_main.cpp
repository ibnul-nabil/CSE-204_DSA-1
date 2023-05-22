#include<bits/stdc++.h>

#include "Arr.h"
//#include "LL.h"

#include "Stack.h"
#include "Queue.h"


using namespace std;

int main(){

    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int k,x;
    in >> k >> x;

    Queue<int> que;
    Stack<int> stck;

    for (int i=0;i<k;i++){
        int a;
        in>> a;
        que.enqueue(a);
    }

    int m,y;
    in >> m >> y;

    for (int i=0;i<k;i++){
        int a;
        in>> a;
        stck.push(a);
    }

    int Q;
    in >> Q;


    out << "QUEUE : "<< que.print() << "STACK : " << stck.print() ;
    
    while(Q--){
        int F , P;
        in >> F  >> P;

        if (F==1){
            que.clear();
            out<< que.print() << "-1\n";
        }
        else if (F==2){
            que.enqueue(P);
            out << que.print() << "-1\n";
        }
        else if (F==3){
            auto t=que.dequeue();
            out << que.print() << t << endl;
        }
        else if (F==4){
            out<< que.print() << que.length() << endl;
        }
        else if (F==5){
            out << que.print() << que.frontValue() << endl;
        }
        else if (F==6){
            out << que.print() << que.rearValue() << endl;
        }
        else if (F==7){
            auto t=que.leaveQueue();
            out << que.print() << t << endl;
        }
        else if (F==8){
            stck.clear();
            out << stck.print() << "-1\n";
        }
        else if (F==9){
            stck.push(P);
            out << stck.print() << "-1\n";
        }
        else if (F==10){
            auto t=stck.pop();   
            out << stck.print() << t  <<  endl;
        }
        else if (F==11){ 
            out << stck.print() << stck.length() << endl;
        }
        else {
            out << stck.print() << stck.topValue() << endl;
        }
        
    }

    in.close();
    out.close();


    return 0;
}