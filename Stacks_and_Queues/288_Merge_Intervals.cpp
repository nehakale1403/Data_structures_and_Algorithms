#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    stack<pair<int, int>> st;
    st.push({v[0].first, v[0].second});

    for(int i=1; i<n; i++){
        int start1 = st.top().first;
        int end1 = st.top().second;

        int start2 = v[i].first;
        int end2 = v[i].second;

        if(end1<start2){
            st.push({start2, end2});
        }else{
            st.pop();
            end1 = max(end1, end2);
            st.push({start1, end1});
        }
    }

    while(!st.empty()){
        cout<<st.top().first<<" "<<st.top().second<<endl;
        st.pop();
    }

}