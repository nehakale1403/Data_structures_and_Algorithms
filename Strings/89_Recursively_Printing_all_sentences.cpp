#include<bits/stdc++.h>
using namespace std;
#define r 3
#define c 3

void printUtil(string arr[r][c], int m, int n, string output[r])
{
    // Add current word to output array
    output[m] = arr[m][n];
 
    // If this is last word of current output sentence, then print
    // the output sentence
    if (m==r-1)
    {
        for (int i=0; i<r; i++)
           cout << output[i] << " ";
        cout << endl;
        return;
    }
 
    // Recur for next row
    for (int i=0; i<c; i++)
       if (arr[m+1][i] != "")
          printUtil(arr, m+1, i, output);
}

void print(string arr[r][c]){
    string output[r];

    for(int i=0; i<c; i++){
        cout<<"In print"<<endl;
        if (arr[0][i] != "")
        printUtil(arr, 0, i, output);
    }
}
int main(){

    string arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cin>>arr[i][j];
    }
    print(arr);
}