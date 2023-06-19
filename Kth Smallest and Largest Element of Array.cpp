#include <bits/stdc++.h> 
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
	// Write your code here.
	// priority_queue<int> pq;
	// for(auto it: arr)pq.push(it);
	// int kk =k;
	// while(kk!=1){
	// 	kk--;
	// 	pq.pop();
	// }
	// int klargest = pq.top();
	// priority_queue<int, vector<int> , greater<int>>pql;
	// for(auto it: arr)pql.push(it);
	// while(k!=1){
	// 	k--;
	// 	pql.pop();
	// }
	// int ksmallest = pql.top();
	sort(arr.begin(), arr.end());
	
	return {arr[k-1],arr[abs(n-k+1)]};
}