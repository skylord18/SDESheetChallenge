#include<bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
    sort(arr, arr+n);
    sort(dep, dep+n);
    int maxi = 1, i = 1, j = 0, curr = 1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            curr++;
            i++;
            
        }else{
            j++;
            curr--;
        }
        maxi = max(maxi, curr);
    }
    return maxi;
}

