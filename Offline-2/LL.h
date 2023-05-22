#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node{

public :
    T data;
    Node<T> *previous;
    Node<T> *next;

    Node(T data, Node<T> *previous=nullptr, Node<T> *next=nullptr){
        this->data=data;
        this->previous=previous;
        this->next=next;
    }
};

template<typename T>
class MyList{
private:
    Node<T> *head;
    int barPosition;
    int length;
public :
    MyList(){
        head=nullptr;
        barPosition=0;
        length=0;
    }
    MyList(int k,int len){
        head=nullptr;
        barPosition=0;
        length=0;
    }
    //1 size
    int size(){
        int s=0;
        Node<T> * current=head;
        while(current!=nullptr){
            s++;
            current=current->next;
        }
        length=s;
        return s;
    }
    
    //push()
    void push(T a){
        if (head==nullptr){
            head=new Node<T> (a,nullptr,nullptr);
            length++;
            return;
        }
        if (barPosition==0){
            Node<T> *current=head;
            Node<T> *temp=new Node<T>(a,nullptr,current);
            current->previous=temp;
            head=temp;
        }
        else {
            Node<T> *current=head;
            for (int i=0;i<barPosition-1;i++){
                current=current->next;
            }
            Node<T> *temp=new Node<T>(a,current,current->next);
            current->next=temp;
        }
        length++;
    }

    //3 pushBack()
    void pushBack(T a){
        if(head==nullptr){
            head=new Node<T>(a,nullptr,nullptr);
        }
        else{
            Node<T> *current=head;
            while(current->next!=nullptr){
                current=current->next;
            }
            Node<T> *temp=new Node<T>(a,current,nullptr);
            current->next=temp;    
        }
        length++;

    }
    //4 erase
    T erase(){
        if (head==nullptr){
            return -1;
        }
        if (size()==1){
            Node<T> *current =head;
            T ret =current->data;
            clear();
            return ret;
        }
        else {        
            if (barPosition==0){
                Node<T> *current =head;
                T ret=current->data;
                current->next->previous=nullptr;
                head=current->next;
                delete current;
                length--;
                if (length<0) length=0;
                return ret;

            }
            else if (barPosition<length-1){
                Node<T> *current=head;
                for (int i=0;i<barPosition;i++){
                    current=current->next;
                }
            
                current->next->previous=current->previous;
                current->previous->next=current->next;
                T ret=current->data;
                delete current;
                length--;
                if (length==barPosition) barPosition--;
                if (barPosition<0) barPosition=0;
                if (length<0) length=0;
                return ret;
            }
            else {
                Node<T> *current=head;
                while(current->next!=nullptr){
                    current=current->next;
                }
                Node<T> *temp=current->previous;
                temp->next=nullptr;
                T ret=current->data;
                delete current;
                length--;
                if (length==barPosition) barPosition--; 
                if (barPosition<0) barPosition=0;
                if (length<0) length=0;
                return ret;

            }
        }
        
    }
    //5 setToBegin
    void setToBegin(){ barPosition=0; }
    //6 setToEnd
    void setToEnd(){ barPosition=length-1;}
    //7 prev
    void prev(){
        if (barPosition>0) barPosition--;
    }
    //8 next
    void next(){
        if (barPosition<length-1) barPosition++;
    }
    //9 currPos
    int currPos(){ return barPosition; }
    //10 setToPos()
    void setToPos(int pos){ barPosition=pos; }
    //11 getValue
    T getValue(){
        Node<T> *current=head;
        for (int i=0;i<barPosition;i++){
            current=current->next;
        }
        return current->data;
    }
    //12 find
    int find(T a){
        Node<T> *current= head;
        for (int i=0;i<length;i++){
            if (current->data==a){
                return i;
            }
            current=current->next;
        }
        return -1;

    }
    //13 clear
    void clear(){
        length=0;
        barPosition=0;
        Node<T> *current= head;
        while(current!=nullptr){
            Node<T> *temp= current->next;
            delete current;
            current=temp;
        }
        head=nullptr;
    }
    //destructor 
    ~MyList(){
        clear();
    }

    string print(){
        string str="<";
        Node<T> *current=head;

        for (int i=0;i<length && current!=nullptr ;i++){
            if(i==barPosition && barPosition==0){
                if (length==1){
                    str.append("| "+to_string(current->data));
                }
                else{
                    str.append("| "+to_string(current->data)+", ");
                }
                current=current->next;
            }
            else if(i==barPosition-1 && barPosition!=0){
                str.append(to_string(current->data)+" | ");
                current=current->next;
            }
            else if(i!=length-1){
                str.append(to_string(current->data)+", ");
                current=current->next;
            }
            else {
                str.append(to_string(current->data));
                current->next;
            }

        }
        str.append(">\n");
        return str;
       
    }
    
};
