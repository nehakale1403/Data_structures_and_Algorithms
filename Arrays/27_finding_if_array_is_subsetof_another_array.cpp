//time = O(n1+n2)
//space = O(n1)

#include<bits/stdc++.h>
using namespace std;

bool isSubset(int arr1[], int arr2[], int n1, int n2){

    map <int, int> frequency;

    for(int i=0; i<n1; i++){
        frequency[arr1[i]]++;
    }

    for(int i=0; i<n2; i++){
        if(frequency[arr2[i]]>0)
            frequency[arr2[i]]--;
        else
            return false;
    }
    return true;
}

int main(){

    int n1, n2;
    cin>>n1>>n2;
    int arr1[n1], arr2[n2];

    for(int i=0; i<n1; i++)
        cin>>arr1[i];

    for(int i=0; i<n2; i++)
        cin>>arr2[i];

    if(isSubset(arr1, arr2, n1, n2))
        cout<<"Yes";
    else
        cout<<"No";
}