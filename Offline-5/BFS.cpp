#include<bits/stdc++.h>
using namespace std;

int main(){
    //taking node and edge num as input
    int n, m;
    cin >> n >> m;

    //making the adjacency list
    vector<int> adj[n];

    for (int i=0;i<m;i++){
        int n1 , n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
    }
    int source ;
    cin >> source;

    //BFS

    bool visited[n]={false};
    queue<int> que;

    int distance[n]={0};
    int pi[n]={0};

    visited[source]=true;
    que.push(source);
    distance[source]=0;
    pi[source]=-1;

    vector <int> pd[n];

    while(!que.empty()){
        int out=que.front(); que.pop();
        for (auto i : adj[out]){
            if (visited[i]) continue;
            visited[i]=true;
            pd[out].push_back(i);
            que.push(i);

            //extra
            distance[i]=distance[out]+1;
            pi[i]=out;
        }
    }

    //for(int i=0;i<n;i++) cout << i << ":  "<<distance[i] << "\n";
    // cout << endl;
    // for(int i=0;i<n;i++) cout << i << ":  "<< pi[i] << "\n";

    //printing the adjacency list of predecessor subgraph
    cout << "BFS tree:\n";
    for (int i=0;i<n;i++){
        if (pd[i].size()){
            cout << i << "-> ";
            for (auto j :pd[i]) cout <<  j << ", ";
            cout <<  endl;
        }    
    }

}