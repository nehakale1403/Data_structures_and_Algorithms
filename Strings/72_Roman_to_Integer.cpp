// https://www.youtube.com/watch?v=dlATMslQ6Uc&ab_channel=AlgorithmsMadeEasyAlgorithmsMadeEasy

#include<bits/stdc++.h>
using namespace std;

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}

int romanToDecimal(string s){

    int res = 0;
    //for eg IV
    for(int i=0; i<s.length(); i++){
        int s1 = value(s[i]); //1

        if(i+1 < s.length()){
            int s2 = value(s[i+1]);//5

            if(s1>=s2){
                res = res+s1;
            }else{
                res = res+s2-s1; //res+4
                i++;
            }
        }else{
            res = res+s1;
        }
    }
    return res;
}

int main(){

    string s;
    cin>>s;
    cout<<romanToDecimal(s);
}   