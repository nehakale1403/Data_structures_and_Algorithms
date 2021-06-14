#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int n, int mid, int k){

    cout<<"Mid ="<<mid<<endl;
    int sum = 0;
    int stu=1;
    for(int i=0; i<n; i++){
        //if the book is having pages greater than mid
        if(arr[i]>mid){
            cout<<arr[i]<<" is greater than "<<mid<<endl;
            return false;
        }   
        //if sum of books for single student is greater than mid, we will take the next student
        if((sum+arr[i])>mid){
            cout<<sum+arr[i]<<" is greater than "<<mid<<endl;
            stu++;
            
            sum=arr[i];
            cout<<"adding student "<<stu<<endl;
            //if students exceeds the required students
            if(stu>k)
                return false;
        }else{
            
            sum+=arr[i];
            cout<<"adding in sum "<<sum<<endl;
        }
    }
    return true;
}

int findPages(int arr[], int n, int k){

    int lb = 0;
    int s = 0;
    int ans=0;

    //we will apply binary search on the sum
    for(int i=0; i<n; i++)
        s+=arr[i];
    
    int ub = s;
    while(lb<=ub){
        int mid = (lb+ub)/2;
        
        //checking if we can allocate 'mid' number of pages to k students
        if(solve(arr, n, mid, k)){
            //if yes, we will try to minimize the pages
            ans = mid;
            ub = mid-1;
        }else{
            //if not we will check for more number of pages
            lb = mid+1;
        }
    }
    return ans;
}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int k;
    cin>>k;

    cout<<findPages(arr, n, k);
}