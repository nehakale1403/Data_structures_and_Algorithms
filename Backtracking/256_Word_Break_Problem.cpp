#include <bits/stdc++.h>
 
using namespace std;
 
// Unordered_map used for storing
// the sentences the key string
// can be broken into
unordered_map<string,
            vector<string> > mp;
 
// Unordered_set used
// to store the dictionary.
unordered_set<string> dict;
 
// Utility function used for
// printing the obtained result
void printResult(vector<string> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << '\n';
}
 
// Utility function for
// appending new words
// to already existing strings
vector<string> combine(
     vector<string> prev, string word){
     
    // Loop to find the append string
    // which can be broken into
    for (int i = 0; i < prev.size(); i++) {
        prev[i] += " " + word;
    }
    return prev;
}
 

vector<string> wordBreakUtil(string s)
{  
    // Condition to check if the
    // subproblem is already computed
    if (mp.find(s) != mp.end())
        return mp[s];
    vector<string> res;
     
    // If the whole word is a dictionary
    // word then directly append into
    // the result array for the string
    if (dict.find(s) != dict.end())
        res.push_back(s);
     
    // Loop to iterate over the substring
    for (int i = 1; i < s.length(); i++) {
        string word = s.substr(i);
         
        // If the substring is present into
        // the dictionary then recurse for
        // other substring of the string
        if (dict.find(word) != dict.end()) {
            string rem = s.substr(0, i);
            vector<string> prev =
             combine(wordBreakUtil(rem), word);
            res.insert(res.end(),
                 prev.begin(), prev.end());
        }
    }
     
    // Store the subproblem
    // into the map
    mp[s] = res;
    return res;
}
 
// Master wordBreak function converts
// the string vector to unordered_set
vector<string> wordBreak(string s, vector<string>& wordDict){
    // Clear the previous stored data
    mp.clear();
    dict.clear();
    dict.insert(wordDict.begin(), wordDict.end());
    return wordBreakUtil(s);
}
 
// Driver Code
int main()
{
    vector<string> wordDict1 = {
        "cat", "cats", "and", "sand", "dog" };
    printResult(wordBreak("catsanddog", wordDict1));
    return 0;
}