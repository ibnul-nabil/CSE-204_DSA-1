#include <bits/stdc++.h>
#include "LL.h"
//#include "Arr.h"
using namespace std;

class LRUCache{
private:
    int track;
    int capacity;
    MyList<int> key;
    MyList<int> value;

public:
    LRUCache(int capacity){
        track=0;
        this->capacity=capacity;
    }
    int get(int k){
        if (key.find(k)!=-1){
            value.setToPos(key.find(k));
            key.setToPos(key.find(k));

            int ret=value.getValue();
            int kk=key.getValue();

            key.erase(); value.erase();
            key.setToBegin(); value.setToBegin();
            key.push(kk) ; value.push(ret);


            return ret;
        }
        return -1;

    }
    void put(int k , int val){

        if (key.find(k)!=-1){
            key.setToPos(key.find(k)); value.setToPos(key.find(k));
            key.erase(); value.erase();
            key.setToBegin(); value.setToBegin();
            key.push(k); value.push(val);            
        }
        else {
            if (track < capacity){
                key.setToBegin(); value.setToBegin();
                key.push(k); value.push(val);
                track++;
            }
            else {
                key.setToEnd(); value.setToEnd();
                key.erase(); value.erase();
                key.setToBegin(); value.setToBegin();
                key.push(k); value.push(val);

            }
            
        }

    }
};