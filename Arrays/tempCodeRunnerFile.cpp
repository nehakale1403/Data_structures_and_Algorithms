#include<bits/stdc++.h>
using namespace std;

int main()
{
//fill your code
int n;
cin >> n;
int arr[n];
for(int i = 0; i < n; i++)
{
cin >> arr[i];
}
int count_odd =0, count_even = 0;
for(int i = 0; i < n; i++)
{
if(arr[i] % 2 == 1)
count_odd++;
else
count_even++;
}
cout << count_odd<<" "<<count_even;

return 0;
}