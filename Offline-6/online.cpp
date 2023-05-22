#include <bits./stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());

    long long total=0;

    int mul=n-1;

    for (int i=0;i<n-1;i++){
        total+=mul*v[i];
        mul--;
    }

    
    double avg=(1.0*total)/n;
    cout << avg << endl;
    return 0;
}