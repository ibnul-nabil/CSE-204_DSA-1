#include<bits/stdc++.h>

//#include "Arr.h"
//#include "LL.h"

using namespace std;

template<typename T>
class Stack{

private:
    MyList<T> myList;
public:
    Stack(){}
    Stack(int len, int size){}

    //clear
    void clear(){
        myList.clear();
    }
    //push()
    void push(T t){
        myList.pushBack(t);
    }
    //pop
    T pop(){
        myList.setToEnd();
        return myList.erase();
    }
    //length
    int length(){
        return myList.size();
    }
    //topValue
    T topValue(){
        myList.setToEnd();    
        return myList.getValue() ;
    }
    //printing 
    string print(){
        myList.setToEnd();
        return myList.print();
    }
};

