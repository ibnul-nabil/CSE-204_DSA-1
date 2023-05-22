#include <bits/stdc++.h>
using namespace std;



int merge(int a[], int start , int mid , int end, vector<pair<int, int>> &v){

    int sizeL=mid-start+1;
    int sizeR=end-mid;

    int L[sizeL];
    int R[sizeR];

    for (int i=0; i<sizeL ;i++) L[i]=a[start+i];
    for (int i=0 ; i<sizeR ;i++) R[i]=a[mid+1+i];

    int count = 0;

    int li=0,
        ri=0,
        i=start;

    while (li < sizeL && ri < sizeR){
        if (L[li] <= R[ri]){
            a[i++]=L[li++];
        }
        else{
            count+= sizeL-li;
            for (int j=0;j<sizeL-li;j++){
                v.push_back(make_pair(L[li+j],R[ri]));
            }
            a[i++]=R[ri++];
        }
       
    }
    while (li < sizeL){
        a[i++]=L[li++];
 
    }
    while (ri < sizeR ){
        a[i++]=R[ri++];
    }

    return count;

}
int inversionCount(int a[], int start, int end, vector<pair<int , int>> &v){
    int count=0;
    if (start < end){
        

        int mid=start+(end-start)/2;

        count+=inversionCount(a, start, mid, v);
        count+=inversionCount(a, mid+1, end, v);

        count+=merge(a, start, mid, end, v) ;
    }
    return count;
}



int main(){
    int n;
    cin >> n;

    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];

    //to store the pairs;
    vector<pair<int,int>> v;

    int c=inversionCount(arr,0,n-1,v);
    cout << c << endl;


    for (auto i: v){
        cout << i.first << " " << i.second << endl;  
    }

    return 0;

}