#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &arr){
    // Write your code here.
    int num1, num2, c1 = 0, c2 = 0, sz=arr.size();
    for(int i = 0;i<sz;i++){
        if(num1==arr[i]){
            c1++;
        }else if(num2==arr[i]){
            c2++;
        }else if(c1==0){
            num1 = arr[i];
            c1++;
        }else if(c2==0){
            num2 = arr[i];
            c2++;
        }else{
            c1--;
            c2--;
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0;i<sz;i++){
        if(arr[i]==num1)cnt1++;
        else if(arr[i]==num2)cnt2++;
    }
    vector<int> ans;
    if(cnt1>sz/3)ans.push_back(num1);
    if(cnt2>sz/3)ans.push_back(num2);
    return ans;
}