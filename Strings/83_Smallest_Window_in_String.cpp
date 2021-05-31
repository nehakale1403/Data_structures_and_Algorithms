#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string str, string pattern){

    //if length of pattern is greater than the string 
    if(str.length() == 0 || str.length()<pattern.length() || pattern.length()==0){
        return "";
    }   

    // map for storing frequency of characters in pattern
    unordered_map<char, int> map;
    //stores the count of matched elements till now
    int matched_ele = 0;
    //start of the window
    int start=0;
    //minimum length of the window and its start point
    int minLen = INT_MAX;
    int minStart = 0;

    //filling the frequency map
    for(int i=0; i<pattern.length(); i++)
        map[pattern[i]]++;
    
    //the window is from start to end
    for(int end=0; end<str.length(); end++){
        char currentChar = str[end];

        //if character is found in map, we will decrease its freq
        if(map.find(currentChar) != map.end()){
            map[currentChar]--;
            //if the character is not an extra one, we will update the matched element
            //once it goes below 0, we are having that character in extra
            if(map[currentChar] >= 0)
                matched_ele++;
        }

        //once the count of matched element is equal to patterns length
        //we will start reducing the window from front
        while(matched_ele == pattern.length()){

            //we will update the minimum window size
            if(end-start+1 < minLen){
                minLen = end-start+1;
                minStart = start;
            }
            //here we shrink the window from front
            char charAtStart = str[start++];
            
            //if the character which got deleted is in our pattern we will increase its frequency
            if(map.find(charAtStart) != map.end()){
                if(map[charAtStart] == 0)
                    matched_ele--;
                map[charAtStart]++;
            }

        }
    }

    //if we do not find the characters, our min len is INT_MAX, annd we have to return null string
    if(minLen>str.length())
        return "";
    
    cout<<minLen<<endl;
    return str.substr(minStart, minLen);
}
int main(){

    string s1, s2;
    cin>>s1>>s2;
    
    cout<<smallestWindow(s1, s2);
}