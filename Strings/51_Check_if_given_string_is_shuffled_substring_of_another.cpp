#include<bits/stdc++.h>
using namespace std;

bool findshuffledstring(string s1, string s2, string res){

    int l1 = s1.length();
    int l2 = s2.length();
    int lr = res.length();

    if((l1+l2) != lr)
        return 0;
    else{
        int flag=0;
        int i=0, j=0, k=0;

        while(k<lr){
            if(i<l1 && s1[i] == res[k]){
                i++;
                k++;
            }else if(j<l2 && s2[j] == res[k]){
                j++;
                k++;
            }else{
                flag=1;
                break;
            }
        }
        if(flag==1)
            return 0;
        else
            return 1;
    }

    
    
}

int main(){
    
    string s1, s2, res;
    cin>>s1>>s2>>res;

    

    if(findshuffledstring(s1, s2, res)){
        cout<<"Yes";
    }else
        cout<<"No";
}