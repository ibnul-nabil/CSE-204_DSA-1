#include<bits/stdc++.h>
#include "BST.h"
using namespace std;

int main(){

    BST bst;

    bst.Insert(9);
    bst.Insert(7);
    bst.Insert(14);
    bst.Insert(6);
    bst.Insert(8);
    bst.Insert(10);
    bst.Insert(16);
    bst.Insert(2);

    cout <<  bst.totalNodes() << endl;
    return 0;
}