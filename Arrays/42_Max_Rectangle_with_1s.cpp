// https://www.youtube.com/watch?v=dAVF2NpC3j4&t=25s&ab_channel=TECHDOSE
// https://www.youtube.com/watch?v=vcv3REtIvEo&ab_channel=TECHDOSE

#include<bits/stdc++.h>
using namespace std;

int main(){

    int r, c;
    cin>>r>>c;

    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }

    int dp[r][c]={0};
    int maximum=0;

    for(int i=0; i<r; i++){
        //finding the left limit
        int leftbound = -1;
        stack<int> st;
        vector<int> left(c);
        for(int j=0; j<c; j++){

            if(arr[i][j]==1){
                arr[i][j] = 1+arr[i-1][j];
                while(!st.empty() && arr[i][st.top()]>=arr[i][j])
                    st.pop();

                int val = leftbound;
                if(!st.empty())
                    val = max(val, st.top());

                left[j] = val;
            }else{
                leftbound = j;
                left[j] = 0;
            }
            st.push(j);
        }

        //clearing the stack
        while(!st.empty())
            st.pop();
        
        //finding the right limit
        int rightbound = c;
        for(int j=c-1; j>=0; j--){

            if(arr[i][j] != 0){

                while(!st.empty() && arr[i][st.top()]>=arr[i][j])
                    st.pop();
                
                int val = rightbound;
                if(!st.empty())
                    val = min(val, st.top());
                
                //calculating area simultaneously
                dp[i][j] = arr[i][j]*((val-1)-(left[j]+1)+1);
                maximum = max(maximum, dp[i][j]);
                st.push(j);

            }else{
                dp[i][j] = 0;
                rightbound = j;
            }
        }

    }
    cout<<maximum;
    
}