#include<bits/stdc++.h>
using namespace std;

template<typename T>
class MyList{

private :
    int capacity;
    int length;
    T *t;
    int end;
    int barPosition;

public :
//constructors
    MyList(){
        capacity=1;
        t=new T[capacity];
        length=0;
        end=-1;
        barPosition=0;
    }
    MyList(int capacity, int length ){

        this->capacity=capacity;
        this->length=length;
        end=-1;
        t= new T[capacity];
        barPosition=0;
    }
//1 size
    int size(){ return end+1;}
//2 push(item)
    void push(T a){
        if (end+1==capacity){
            capacity*=2;
            T * temp= new T[capacity];

            for(int i=0;i<barPosition;i++){
                temp[i]=t[i];
            }
            temp[barPosition]=a;
            for(int i=barPosition+1 ;i<end+2;i++){
                temp[i]=t[i-1];
            }
            delete []t;
            t=temp;
            end++;
        }
        else {
            for(int i=end;i>=barPosition;i--){
                t[i+1]=t[i];
            }
            t[barPosition]=a;
            end++;
        }
    }
//3 pushBack(item)
    void pushBack(T a){
        if (end+1==capacity){
            capacity*=2;
            T *temp=new T[capacity];
            for(int i=0;i<end+1;i++){
                temp[i]=t[i];
            }
            temp[++end]=a;
            delete []t;
            t=temp;
        }
        else {
            t[++end]=a;
        }
    }
//4 erase
    T erase(){
        if (size()==0){
            return -1;
            //return stype{};
        }

        if (end < capacity/2){
            capacity/=2;

            T *temp=new T[capacity];

            for (int i=0;i<barPosition;i++){
                temp[i]=t[i];
            }
            T ret=t[barPosition];
            for (int i=barPosition;i<end;i++){
                temp[i]=t[i+1];
            }
            delete []t;
            t=temp;
            if (barPosition==end) { barPosition--;}
            end--;

            //edit
            if (barPosition<0) barPosition=0;
            //
            return ret;
        }
        else {
            T ret=t[barPosition];
            for (int i=barPosition;i<end;i++){
                t[i]=t[i+1];
            }
            if(barPosition==end) { barPosition--;}
            end--;
            //edit
            if (barPosition<0) barPosition=0;
            //edit
            return ret;
        }
        
    }

//5 setToBegin
    void setToBegin(){ barPosition=0; }
//6setToEnd
    void setToEnd(){
        if (end==-1){
            barPosition=0;
        }
        else {
            barPosition=end;
        }
    }

//7 perv
    void prev(){
        if (barPosition>0){ barPosition--; }
    }
//8 next
    void next(){
        if (barPosition<end) { barPosition++; } 
    }
//9 currPos
    int currPos(){ return barPosition; }
//10 setToPos(pos)
    void setToPos(int pos){ barPosition=pos;}
//11 getValue
    T getValue(){ return t[barPosition];}
//12 find(item)
    int find(T a){
        for (int i=0;i<end+1;i++){
            if (t[i]==a){
                return i;
            }
        }
        return -1;
    }
//13 clear
    void clear(){
        capacity=1;
        length=0;
        end=-1;
        barPosition=0;
        delete []t;
        t=new T[capacity];
    }
//destructor 
    ~MyList(){
        delete [] t;
    }

    T operator[](int i){ return t[i];}

    string print(){
        string str="<";
        //std::cout <<"<";
        for (int i=0;i<end+1;i++){
            if (i==barPosition && barPosition==0){
                if (end+1==1){
                    str.append("| "+to_string(t[i]));
                }
                else {
                    str.append("| "+to_string(t[i])+", ");
                }
            }
            else if (i==barPosition-1 && barPosition!=0){
                str.append(to_string(t[i])+" | ");
                //std::cout << t[i]<<" | " << t[i+1] <<", ";
            }
            else if(i!=end){
                str.append(to_string(t[i])+", ");
                //std::cout << t[i] << ", ";
            }
            else {
                str.append(to_string(t[i]));
                //std::cout << t[i] <<">\n";
            }   
        }
        str.append(">\n");
        return str;
        
    }

};

