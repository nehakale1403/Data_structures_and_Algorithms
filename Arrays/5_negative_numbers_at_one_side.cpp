#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n], temp, j=0;
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	// for(int i=0; i<n; i++){
	//     if(arr[i]<0){
	//         if(i!=j)
	//             swap(arr[i], arr[j]);
	//         j++;
	//     }
	// }
	
	int l=0, r=n-1;
	while(l<r){
		while(arr[l]<0) l++;
		while(arr[r]>0) r--;
		swap(arr[l], arr[r]);
		l++;
		r--;
	}

	for(int i=0; i<n; i++){
	    cout<<arr[i]<<" ";
	}
 
	
	
	return 0;
}