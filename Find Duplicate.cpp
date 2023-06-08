#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	// map<int,int> mpp;
	// for(int i =0;i<n;i++)mpp[arr[i]]++;
	// for(auto it: mpp){
	// 	if(it.second>=2)return it.first;
	// }
	int slow = arr[0], fast = arr[0];
	do{
		slow = arr[slow];
		fast = arr[arr[fast]];
	}while(slow != fast);
	fast = arr[0];
	while(slow != fast){
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}
