#include<bits/stdc++.h>
using namespace std;

//User function Template for C++

string reverseWord(string str){

  int n=str.length();
  char temp;
  int i=0, j=n-1;
  while(i<j){
      temp=str[i];
      str[i]=str[j];
      str[j]=temp;
      i++;
      j--;
  }
  
  return str;
}

int main(){
  string str;
  cin>>str;
  cout<<reverseWord(str);
  return 0;
}