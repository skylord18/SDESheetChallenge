#include <bits/stdc++.h> 
long long maxSubarraySum(int nums[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long int maxi = 0 ;long long int curSum = 0;
    for (int i = 0; i < n; i++) {
        curSum +=nums[i];
        maxi = max(maxi, curSum);
        if(curSum<0)curSum = 0;
    }
    return maxi;
}