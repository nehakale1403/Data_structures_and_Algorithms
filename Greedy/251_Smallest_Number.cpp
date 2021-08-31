#include<bits/stdc++.h>
using namespace std;

void findSmallest(int s, int d){

    if(s == 0){
        (d == 1)? cout<<"0" : cout<<"not possible"<<endl;
        return;
    }

    if(s > 9*d){
        cout<<"not possible"<<endl;
        return;
    }

    int res[d];

    s -= 1;

    for(int i= d-1; i>0; i--){
        if(s > 9){
            res[i] = 9;
            s -= 9;
        }else{
            res[i] = s;
            s = 0;
        }
    }

    res[0] = s+1;

    for(int i=0; i<d; i++) cout<<res[i];

}

int main(){
    
    int sum, digits;
    cin>>sum>>digits;

    findSmallest(sum, digits);

}