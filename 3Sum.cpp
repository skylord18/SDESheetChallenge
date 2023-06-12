#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for(int i =0;i<n-2;i++){
		int t = K - nums[i];
		int low = i+1, high = n-1;
		while(low<high){
			if(nums[low] + nums[high] == t){
				vector<int> temp = {nums[i], nums[low], nums[high]};
				ans.push_back(temp);
				while(low<high && nums[low]==nums[low+1])low++;
				while(low<high && nums[high]== nums[high-1])high--;
				low++;
				high--;
			}else if(nums[low] + nums[high]>t){
				high--;
			}else{
				low++;
			}
		}
		while(i<n && nums[i] == nums[i+1])i++;
	}
	return ans;
}