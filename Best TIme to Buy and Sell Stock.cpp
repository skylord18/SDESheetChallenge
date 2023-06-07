#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int maxProfit = 0, minPrice = prices[0];
    for(int i = 0;i<prices.size();i++){
        minPrice = min(minPrice,prices[i]);
        maxProfit = max(maxProfit,prices[i]- minPrice);
    }
    return maxProfit;
}