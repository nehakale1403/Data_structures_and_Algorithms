#include<bits/stdc++.h>
using namespace std;

bool isValid(string &str){
    if(str.length() > 3)
        return false;
    if(str.front() == 0 && str.length()>1)
        return false;
    int val = stoll(str);
    return (val>=0 && val<=255);
}
void computeAllValidIP(string &str, vector<string> &res){

    for(int i=1; i<=3 && i<str.length(); i++){
        string first = str.substr(0, i);

        if(isValid(first)){
            for(int j=1; j<=3 && i+j<str.length(); j++){

                string second = str.substr(i, j);
                if(isValid(second)){
                    
                    for(int k=1; k<=3 && i+j+k <str.length(); k++){

                        string third = str.substr(i+j, k);
                        string fourth = str.substr(i+j+k);
                        if(isValid(third) && isValid(fourth)){
                            res.emplace_back(first+"."+second+"."+third+"."+fourth);
                        }
                    }
                }
            }
        }
    }
}
int main(){

    string s;
    cin>>s;

    vector<string> res;

    computeAllValidIP(s, res);

    for(auto i:res)
		cout<<i<<"\n";
}