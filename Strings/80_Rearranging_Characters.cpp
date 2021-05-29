#include<bits/stdc++.h>
using namespace std;

char getMaxCountChar(const vector<int>& count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = 'a' + i;
        }
    }
 
    return ch;
}

string rearrangeString(string s){

    int n = s.size();
    if(!n)
        return "";
    
    vector<int> count(26, 0);
    for(auto ch: s)
        count[ch-'a']++;

    char ch_max = getMaxCountChar(count);
    int maxCount = count[ch_max - 'a'];

    //maxcount char cannot be adjusted at alternate positions
    if (maxCount > (n + 1) / 2)
        return "";

    string res(n, ' ');
    int ind=0;
    //filling the alternate posoitions
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return res;
    
}

int main(){
    string s;
    cin>>s;

    string res = rearrangeString(s);
    if (res == "")
        cout << "Not Possible" << endl;
    else
        cout << res << endl;
    return 0;
}
