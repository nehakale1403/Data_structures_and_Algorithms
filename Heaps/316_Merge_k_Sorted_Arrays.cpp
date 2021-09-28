#include<bits/stdc++.h>
using namespace std;

#define N 105

void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

vector<int> mergeKArrays(vector<vector<int>> arr, int k){
        //code here
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                heap.push(arr[i][j]);
            }
        }
        
        vector<int> res;
        
        for(int i=0; i<k*k; i++){
            res.push_back(heap.top());
            heap.pop();
        }
        
        return res;
}

int main(){
        int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }

        vector<int> output = mergeKArrays(arr, k);
        printArray(output, k*k);
}