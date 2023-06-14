#include <bits/stdc++.h> 
using namespace std;
bool static comparator(pair<int,int> p1, pair<int,int> p2){
    double val1 = (double)p1.first/(double)p1.second;
    double val2 = (double)p2.first/(double)p2.second;
    if(val1<val2)return false;
    return true;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w){
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(),comparator);
    int currWeight = 0;
    double valStolen = 0.0;
    for(int i =0;i<n;i++){
        if(currWeight + items[i].first<=w){
            currWeight += items[i].first;
            valStolen+=items[i].second;
        }else{
            int remainingWt = w - currWeight;
            valStolen+=(items[i].first/(double)items[i].second) * remainingWt;
            break;
        }
    }
    return valStolen;
}