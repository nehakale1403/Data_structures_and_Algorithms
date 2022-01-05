#include <bits/stdc++.h>
using namespace std;

int kadane(int* temp, int* start, int* finish, int n){
    int sum = 0, maxSum = INT_MIN, i;
 
    // Just some initial value to check
    // for all negative values case
    *finish = -1;
 
    // local variable
    int local_start = 0;
 
    for (i = 0; i < n; ++i)
    {
        sum += temp[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
 
    // There is at-least one
    // non-negative number
    if (*finish != -1)
        return maxSum;
 
    // Special Case: When all numbers
    // in arr[] are negative
    maxSum = temp[0];
    *start = *finish = 0;
 
    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (temp[i] > maxSum)
        {
            maxSum = temp[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}


void findMaxSumMatrix(vector<vector<int>> arr, int r, int c){

    int max_sum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;

    int left, right, i;
    int temp[r], sum, start, finish;

    for(left = 0; left < c; left++){
        memset(temp, 0, sizeof(temp));

        for(right = left; right<c; right++){
            for(i = 0; i<r; i++)
                temp[i] += arr[i][right];
            
            sum = kadane(temp, &start, &finish, r);
            if (sum > max_sum) {
                max_sum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    cout << "(Top, Left) ("
         << finalTop << ", "
         << finalLeft
         << ")" << endl;
    cout << "(Bottom, Right) ("
         << finalBottom << ", "
         << finalRight << ")" << endl;
    cout << "Max sum is: " << max_sum << endl;
}

int main(){

    int r, c;
    cin>>r>>c;

    vector<vector<int>> arr(r, vector<int> (c));

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>arr[i][j];

    findMaxSumMatrix(arr, r, c);
}