#include<bits/stdc++.h>
using namespace std;

int minlength(string arr[], int n)
{
    int min = arr[0].length();
 
    for (int i=1; i<n; i++)
        if (arr[i].length() < min)
            min = arr[i].length();
 
    return(min);
}

string commonPrefix(string arr[], int n){

    int minlen = minlength(arr, n);

    string result = "";
    char current;

    for(int i=0; i<minlen; i++){
        current = arr[0][i];

        //checking for all the strings    
        for(int j=1; j<n; j++){
            if(arr[j][i] != current)
                return result;
        }

        result.push_back(current);
    }
    return result;
}

int main(){
    
    int n;
    cin>>n;

    string arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<commonPrefix(arr, n);
}