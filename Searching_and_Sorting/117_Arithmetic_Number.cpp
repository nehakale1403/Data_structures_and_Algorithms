#include<bits/stdc++.h>
using namespace std;

int main(){

    double a, b, c;
    cin>>a>>b>>c;
    
    double x = double((b-a)/c);
    long long int n=x;
    cout<<n<<" "<<x<<endl;
    double temp = x-n;
    cout<<temp<<endl;
    if(temp>0 || (b<a && c>0) || (b>a && c<0) || (c==0 && a!=b))
        cout<<0;
    else
        cout<<1;
    
}