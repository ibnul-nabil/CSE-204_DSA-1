#include<bits/stdc++.h>
using namespace std;

bool visited[10000]={false};
vector<int> pd[10000];

void dfs(int start , vector<int> a[],vector<int> pd[]){

    if (visited[start]) return;
    visited[start]=true;

    for (auto i: a[start]){ 
        if (visited[i]) continue;
        pd[start].push_back(i);
        dfs(i,a,pd);
    }
}

int main(){
    //taking node and edge num as input
    int n, m;
    cin >> n >> m;

    //making the adjacency list
    vector<int> adj[n+1];

    for (int i=0;i<m;i++){
        int n1 , n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2); 
    }

    int source;
    cin >> source;
    
    //starting dfs
    dfs(source,adj,pd);

    // printing predecessor
    cout << "DFS tree:\n";
    for (int i=0;i<n;i++){
        if (pd[i].size()){
            cout << i << "-> ";
            for (auto j :pd[i]) cout <<  j << ", ";
            cout <<  endl;
        }    
    }
    return 0;
}