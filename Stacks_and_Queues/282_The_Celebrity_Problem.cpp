#include<bits/stdc++.h>
using namespace std;
#define n 3
int arr[n][n];
bool knows(int a, int b)
{
    return arr[a][b];
}

int main(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    stack<int> s;

    int c;

    for(int i=0; i<n; i++)
        s.push(i);

    while(s.size()>1){

        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(a, b))
            s.push(b);
        else    
            s.push(a);
   
    }
    if(s.empty()){
        cout<<-1;
        return 0;
    }
        
    
    c = s.top();
    s.pop();

    for(int i=0; i<n; i++){
        if((i != c) && (knows(c, i) || !knows(i, c))){
            cout<<-1;
            return 0;
        }
            
    }
    cout<<c;

}