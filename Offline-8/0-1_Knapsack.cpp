#include <bits/stdc++.h>
using namespace std;



int knapsack(vector<pair<int,int>> &v, int capacity, vector<int> &weights , map<int, int> &mp){

    int N=v.size()+1;

    int table[N][capacity+1];

    for (int i=0; i< N ; i++){
        for (int j=0; j<capacity+1 ; j++){
            if (i==0 || j==0){
                table[i][j]=0;
            }
            else if(v[i-1].first <= j){

                int in = v[i-1].second+ table[i-1][j-v[i-1].first];
                int prv = table[i-1][j];
                if (in >= prv ){
                    table[i][j]= in;
                    /*
                    if (mp[v[i-1].first]) continue;
                    else {
                        weight.pop_back();
                        weights.push_back(v[i-1].first);
                        mp[v[i-1].first]=true;
                    }
                    */

                }
                else{
                    table[i][j]= prv;
                }
            }
            else{
                table[i][j]= table[i-1][j];
            }
        }


    }
    /*
    for (int i=0;i<N;i++){
        for (int j=0;j<=capacity ;j=j+10){
            cout << table[i][j] << " ";
        }
        cout  << endl;
    }
    */

    int row=N-1 , col=capacity;

    for (int i=0;i<N;i++){
        if (table[row][col]==0)  break;
        if (table[row][col]!=table[row-1][col]){
            //cout << table[row][col] << endl;
            weights.push_back(mp[row]);
            col=col-mp[row];
            row--;

        }
        else row--;
    }

    return table[N-1][capacity];


}

int main(){
    int n; cin >> n;

    vector<pair<int , int>> v(n);
    map<int, int> mp;

    for (int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
        mp[i+1]=v[i].first;
    }

    int capacity; cin >> capacity;

    vector<int> weights;

    int maxVal=knapsack(v,capacity,weights,mp);
    cout << maxVal << endl;
    for (auto i : weights ) cout  << i <<  " ";
    cout << endl;


    return 0;
}
