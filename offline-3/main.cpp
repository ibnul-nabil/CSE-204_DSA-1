#include<bits/stdc++.h>
#include "BST.h"
using namespace std;

int main(){

    BST bst;

    ifstream in;
    
    freopen("output.txt","w",stdout);

    in.open("input.txt");
   

    string s1,s2;

    while (!in.eof()){
        in >> s1 >> s2;

        if (s1=="I"){
            int x=stoi(s2);
            bst.Insert(x);
            bst.print(4);
        }
        else if(s1=="D"){
            int x=stoi(s2);
            bst.Delete(x);  
                 
        }
        else if(s1=="F"){
            int x=stoi(s2);
            bool t=bst.Find(x);
            if (t){
                cout << "True\n";
            }
            else {
                cout << "False\n";
            }

        }
        else if (s1=="T"){
            if (s2=="In"){
                bst.print(1);
            }
            else if (s2=="Post"){
                bst.print(3);
            }
            else if (s2=="Pre"){
                bst.print(2);
            }
        }
        else if (s1=="H"){
            bst.Height();
        }
        else if (s1=="P"){
            int x=stoi(s2);
            cout<< "depth is " << bst.Depth(x) << endl; 
        }
        else if (s1=="Min"){
            bst.getMin();
        }
        else if (s1=="Max"){
            bst.getMax();
        }
    }
    in.close();
    return 0;
}