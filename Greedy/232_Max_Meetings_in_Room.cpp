#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

bool comp(struct meeting a, meeting b){
    return (a.end<b.end);
}

void printMeetings(int start[], int end[], int n){

    struct meeting meet[n];
    for(int i=0; i<n; i++){
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i+1;
    }

    sort(meet, meet+n, comp);

    vector<int> m;

    m.push_back(meet[0].pos);

    int time_limit = meet[0].end;

    for(int i=1; i<n; i++){
        if(meet[i].start >= time_limit){
            m.push_back(meet[i].pos);
            time_limit = meet[i].end;
        }
    }

    for(int i=0; i<m.size(); i++){
        cout<<m[i]<<" ";
    }

}

int main(){
    int n;
    cin>>n;

    int start[n];
    int end[n];
    for(int i=0; i<n; i++) cin>>start[i];
    for(int i=0; i<n; i++) cin>>end[i];

    printMeetings(start, end, n);
}