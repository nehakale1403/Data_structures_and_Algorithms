#include<bits/stdc++.h>
using namespace std;

int largestArea(vector<int> &arr){
    
    int n = arr.size();
    vector<int> left(n), right(n);

    stack<int> st;

    //finding left limit
    for(int i=0; i<n; ++i){

        if(st.empty()){

            left[i] = 0;
            st.push(i);
        
        }else{
            while((!st.empty()) and arr[st.top()] >= arr[i]){
                st.pop();
            }
    
            left[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
    }
    

    //clearing the stack
    while(!st.empty())
        st.pop();
    
    //finding the right limits
    for(int i=n-1;i>=0; i--){
        if(st.empty()){
            right[i] = n-1;
            st.push(i);
        }else{
            while(!st.empty() && arr[st.top()]>= arr[i])
                st.pop();
            
            right[i] = st.empty()?n-1:st.top()-1;
            st.push(i);
        }
    }

    int max_area = 0;
    for(int i=0; i<n; i++){
        max_area = max(max_area, arr[i] * (right[i] - left[i] + 1));
    }
    return max_area;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    cout<<largestArea(arr);

}