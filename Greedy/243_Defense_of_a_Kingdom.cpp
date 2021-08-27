#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int r, c;
    cin>>r>>c;

    int n;
    cin>>n;

    vector<int> a;
    vector<int> b;
    a.push_back(0);
    b.push_back(0);

    while(n--){
        int x, y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    a.push_back(r+1);
    b.push_back(c+1);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mx=0, my = 0;
    for(int i=0; i<a.size()-1; i++){
        mx = max(mx, a[i+1] - a[i] - 1);
        my = max(my, b[i+1] - b[i] - 1);
    }
    cout<<mx*my;
}