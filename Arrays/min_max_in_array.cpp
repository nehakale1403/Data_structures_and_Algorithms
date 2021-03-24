#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int min=INT_MAX, max=INT_MIN;
	cin>>n;
	int arr[n];
	for(int i=0; i<n;i++){
	    cin>>arr[i];
	    if(arr[i]>max)
	        max=arr[i];
	    if(arr[i]<min)
	        min=arr[i];
	}
	 
	cout<<min<<" "<<max<<endl;   
	
	
	return 0;
}