#include<bits/stdc++.h>
using namespace std;
struct activity{
    int start;
    int end;
    int pos;
};
bool static comparotor(struct activity a1, struct activity a2){
    if(a1.end<=a2.end)return true;
    else if(a2.end>a1.end)return false;
    else if(a1.pos<a2.pos)return true;
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    //vector<vector<int>> allActivities;
    int pos  = 0;
    struct activity activity [start.size()];
    
    for(int i =0;i<start.size();i++){
        activity[i].start = start[i], activity[i].end = finish[i] , activity[i].pos = ++pos;
    }
    sort(activity, activity+start.size(),comparotor);
    int activityCount = 1, lastActivityEnd = activity[0].end;
    for(int i =1;i<start.size();i++){
        if(lastActivityEnd<=activity[i].start){
            activityCount++;
            lastActivityEnd = activity[i].end;
        }
    }
    return activityCount;
}