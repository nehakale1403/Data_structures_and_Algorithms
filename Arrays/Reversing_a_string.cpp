

//User function Template for C++

string reverseWord(string str){
    
  //Your code here
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