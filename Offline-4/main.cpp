#include <bits/stdc++.h>
#include "minHeap.h"
using namespace std;


int main(){



    minHeap heap;

    ifstream in;
    
    freopen("output.txt","w",stdout);

    in.open("input.txt");

    string s;
    int t,d;

    while(!in.eof()){
        in >> s ;

        if (s=="INS"){
            in >>t;
            heap.Insert(t);
            cout << "INSERTED " << t <<  endl;
        }
        else if (s=="PRI"){
            heap.Print();
        }
        else if (s=="DEC"){
            in >> t >> d;
            heap.DecreaseKey(t,d);

        }
        else if (s=="FIN"){
            int x=heap.FindMin();
            if (x==-1){
                cout << "Empty heap\n";
            }
            else{
                cout << "FindMin returned " << x << endl;
            }
        }
        else if (s=="EXT"){
            int x=heap.ExtractMin();
            if (x==-1){
                cout << "Empty heap\n";
            }
            else{
                cout << "ExtractMin returned " << x << endl;

            }
        }
       
    }




    

    return 0;
}