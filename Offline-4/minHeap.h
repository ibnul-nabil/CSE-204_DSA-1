// messed up function naming 


#include<bits/stdc++.h>
using namespace std;


#define default_size 10


class minHeap{

private:
    int *arr;
    int heapSize;
    int max_size;

    // 
    int left(int i){ return 2*i; }
    int right(int i){ return 2*i+1; }
    int parent(int i) { return i/2; }

    void build_heap(int i);
    void min_heapify(int i);
    int find(int key);
public:
    minHeap();
    minHeap(int n);
    
    int FindMin(){ 
        if (heapSize >= 1){
            return arr[1];
        }else {
            return -1;
        }        
    }
    int ExtractMin();
    void Insert(int element);
    void DecreaseKey(int prevKey, int newKey);
    void Print();


};

minHeap::minHeap(){
    arr= new int[default_size+1];
    heapSize=0;
    max_size=10;
}
minHeap::minHeap(int n){
    arr=new int[n+1];
    heapSize=0;
    max_size=n;
}

void minHeap::build_heap(int i){

    int par=parent(i);

    if (par >= 1 && arr[i] < arr[par]){
        swap(arr[i],arr[par]);
        build_heap(par);
    }

}


void minHeap::Insert(int element){

    if (heapSize >= max_size){
        max_size *= 2;
        int *temp = new int[max_size+1];

        for (int i=1;i<=heapSize;i++){
            temp[i]=arr[i];
        }

        delete []arr;
        arr=temp;
    }

    arr[++heapSize]=element;
    build_heap(heapSize);

} 

void minHeap::min_heapify(int i){


    int left_child, right_child, smallest;
    left_child=left(i);
    right_child=right(i);


    if (left_child <= heapSize && arr[left_child] < arr[i] ){
        smallest=left_child;
    }else {
        smallest=i;
    }

    if (right_child <= heapSize && arr[right_child] < arr[smallest]){
        smallest =right_child;
    }

    if (smallest != i){
        swap(arr[smallest],arr[i]);
        min_heapify(smallest);
    }

}

int minHeap::ExtractMin(){

    if (heapSize < 1){
        return -1;
    }

    int min=arr[1];
    arr[1]=arr[heapSize--];
    min_heapify(1);
    return min;
}

int minHeap:: find(int key){

    for (int i=1;i<=heapSize;i++){
        if (key==arr[i]){
            return i;
        }
    }
    return -1;
}

void minHeap:: DecreaseKey(int prevKey, int newKey){

    if (heapSize < 1){
        cout << "Empty heap\n";
        return ;
    }

    int indx_prv=find(prevKey);
    if (indx_prv==-1){
        cout << "Key not found\n";
        return;
    }
    arr[indx_prv]=newKey;
    build_heap(indx_prv);
    cout << prevKey << " decreased to " << newKey  <<  endl;
}

void minHeap:: Print(){
    int level=0;
    int j;
    cout << "Printing the binary heap …\n";
    cout  << "-----------------------------------------------------------------------------\n";
    for (int i=1;i<=heapSize;){
        cout << "Level " << level << ": "; 
        for (j=0;j<i;j++){
            if (i+j > heapSize ){
                break;
            }
            cout << arr[j+i] << " ";
        }
        i+=j;
        level++;
        cout << endl;
    }
    cout  << "-----------------------------------------------------------------------------\n";
}