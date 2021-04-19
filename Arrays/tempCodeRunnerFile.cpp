#include<bits/stdc++.h>
using namespace std;

int main(){

    int a = 5;
    int *p = &a;
    int **q = &p;
    cout<<a<<endl; //5
    cout<<p<<endl; //addr a
    cout<<q<<endl; //addr p
    cout<<*p<<endl;   //5
    cout<<*q<<endl; //addr p
    cout<<**q<<endl; //5
}