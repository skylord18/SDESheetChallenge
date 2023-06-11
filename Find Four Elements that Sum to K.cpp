#include <bits/stdc++.h>
using namespace std;
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    for(int i =0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            int low = j+1, high = arr.size()-1;
            while(low<=high){
                if(arr[i] + arr[j] + arr[low] + arr[high]==target){
                    return "Yes";
                }else if(arr[i] + arr[j] + arr[low] + arr[high]>target){
                    high--;
                }else {
                    low++;
                }
            }
        }
    }
    return "No";
}
