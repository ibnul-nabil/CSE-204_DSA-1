#include<bits/stdc++.h>

//#include "Arr.h"
//#include "LL.h"

using namespace std;

template<typename T>
class Queue{

private:
    MyList<T> myList;
public:
    Queue(){}
    Queue(int len , int size){}

    //clear
    void clear(){
        myList.clear();
    }
    //enqueue(item) 
    void enqueue(T t){
        myList.setToEnd();
        myList.pushBack(t);
    }
    //dequeue()
    T dequeue(){
        myList.setToBegin();
        return myList.erase();
    }
    //length()
    int length(){
        return myList.size();
    }
    //frontValue()
    T frontValue(){
        myList.setToBegin();
        return myList.getValue() ;
    }
    //rearValue()
    T rearValue(){
        myList.setToEnd();
        return myList.getValue() ;
    }
    //leaveQueue()
    T leaveQueue(){
        myList.setToEnd();
        return myList.erase();
    }

    //printing
    string print(){
        myList.setToBegin();
        return  myList.print();
    }


};
