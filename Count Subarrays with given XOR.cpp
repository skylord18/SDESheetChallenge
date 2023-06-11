#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x){
    //    Write your code here.
    int cnt = 0, xorr = 0;
    map<int,int> mpp;
    for(int i = 0;i<arr.size();i++){
        xorr = xorr ^arr[i];
        if(xorr==x)cnt++;
        if(mpp.find(xorr)!=mpp.end())cnt+=mpp[xorr];
        mpp[xorr]++;
    }
    return cnt;
}