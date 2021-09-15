#include <bits/stdc++.h>
using namespace std;
 
bool check(int l, int r, int n) {
  if (__builtin_popcount(l) < __builtin_popcount(r))  return 0;
  else if (__builtin_popcount(l) > __builtin_popcount(r)) return 1;
  string ll(n, '0'), rr(n, '0');
  for (int i = 0; i < n; ++i) {
    if ((l>>i)&1) ll[i] = '1';
    if ((r>>i)&1) rr[i] = '1';
  }
  return (rr > ll);
}
 
int main() {
 
  int t;
  cin>>t;
  while(t--){
        int n, req;
        cin >> n >> req;
        
        int ans = -1;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
        
        for (int i = 0; i < (1<<n); ++i) {
            int tmp = 0;
            for (int j = 0; j < n; ++j) {
            if ((i>>j)&1) tmp += a[j];
            }
            if (tmp == req) {
            if (ans == -1)  ans = i;
            else if (check(ans, i, n)) ans = i;
            }
        }
        
        if (ans == -1)  cout << -1;
        else {
            for (int i = 0; i < n; ++i)
            if ((ans>>i)&1) cout << i+1 << " ";
        }
        cout << '\n';
  }
  
}