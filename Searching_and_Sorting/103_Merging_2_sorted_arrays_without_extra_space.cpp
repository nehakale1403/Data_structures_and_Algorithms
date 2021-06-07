#include <bits/stdc++.h> 
using namespace std; 

// Merge ar1[] and ar2[] with O(1) extra space 
void merge(int ar1[], int ar2[], int m, int n) 
{ 
	// Iterate through all elements of ar2[] starting from 
	// the last element 
	for (int i=n-1; i>=0; i--) 
	{ 
		/* Find the smallest element greater than ar2[i]. Move all 
		elements one position ahead till the smallest greater 
		element is not found */
		int j, last = ar1[m-1]; 
		for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
			ar1[j+1] = ar1[j]; 

		// If there was a greater element 
		if (j != m-2 || last > ar2[i]) 
		{ 
			ar1[j+1] = ar2[i]; 
			ar2[i] = last; 
		} 
	} 
} 

// Driver program 
int main(){ 

    int m,n;
    cin>>m>>n;

    int ar1[m], ar2[n];
    for(int i=0; i<m; i++) cin>>ar1[i];
    for(int i=0; i<n; i++) cin>>ar2[i];

	merge(ar1, ar2, m, n); 

	for (int i=0; i<m; i++) 
		cout << ar1[i] << " "; 
	for (int i=0; i<n; i++) 
		cout << ar2[i] << " "; 
return 0; 
}