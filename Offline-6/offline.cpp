#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define forn(n) for (int i=0;i<n;i++)


bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    if (a.second == b.second) return a.first<b.first;
    else return a.second < b.second;
}

int main(){

    int n;
    cin >> n;
    vector<pair<int , int >> data(n);

    for(int i=0;i<n;i++){
       cin >> data[i].first >>  data[i].second;
    }

    sort(data.begin(),data.end(),sortbysec);

    vector <pair <int , int >>  result;

    int end=data[0].second;
    int total=1;
    result.push_back(make_pair(data[0].first,data[0].second));

    for (int i=1;i<n;i++){
        if (data[i].first < end) continue;
        total++;
        end=data[i].second;
        result.push_back(make_pair(data[i].first,data[i].second));
    }

    cout << total << endl;
    for (int i=0;i< total;i++){
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}
