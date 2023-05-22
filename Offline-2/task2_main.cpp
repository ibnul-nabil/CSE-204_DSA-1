#include <bits/stdc++.h>

#include "Arr.h"
//#include "LL.h"

#include "Stack.h"
#include "Queue.h"

using namespace std;

class customer{
public:
    int customer_no;
    int arrival;
    int playtime;

    customer(int a, int b, int c){
        customer_no=a;
        arrival=b;
        playtime=c;
    }
    customer(){}

    void print(){
        cout << customer_no << " " << arrival << " " << playtime << endl;
    }
};

int main(){

    
    int total, Time;
    cin >> total >> Time;

    MyList<customer> m;

    int t_arr[total];

    for (int i=0;i<total;i++){
        int a,b;
        cin >> a >> b;
        t_arr[a];
        customer x(i+1,a,b);
        m.pushBack(x);
    }

    Queue<customer> line1;
    Stack<customer> line2;

    int timer1, timer2;

    m.setToBegin();

    customer x=m.getValue();
    m.next();

    timer1=x.arrival+x.playtime;
    int pc2=0;

    for (int t=0;t<=Time ;t++){
        if (t< timer1){
            if (line1.length() <3 ){
                x=m.getValue();
                line1.enqueue(x);
                m.next();
            }
            else {
                if (pc2==0){
                    x=m.getValue();
                    m.next();
                    timer2=x.arrival+x.playtime;
                    pc2=1;
                }
                if (t < timer2){
                    x=m.getValue();
                    m.next();
                    line2.push(x);
                }
                else{
                    x=line2.pop();
                    timer2+=x.playtime;
                }
            }


        }
        else {
            x=line1.dequeue();
            timer1+=x.playtime;
        }
    }


    
    return 0;
}