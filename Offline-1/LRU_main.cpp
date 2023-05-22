#include<bits/stdc++.h>
//#include "LL.h"
#include"LRUCache.h"

using namespace std;

int main(){

    ifstream in;
    in.open("lru_input.txt");

    ofstream out;
    out.open("lru_output.txt");

    int capacity;
    in>> capacity;

    LRUCache lru(capacity);

    int Q;
    in>> Q;

    int operation;
    while(Q--){
        in >>operation;
        if (operation ==1){
            int k;
            in >> k;
            out << lru.get(k) << endl;
        }
        else{
            int k, val;
            in >> k >> val;
            lru.put(k,val);
        }
    }

    in.close();
    out.close();
    
}