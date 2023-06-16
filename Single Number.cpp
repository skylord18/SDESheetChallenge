#include <bits/stdc++.h> 
using namespace std;
int singleNonDuplicate(vector<int>& arr){
	// Write your code here
	int low = 0, high = arr.size()-1;
	while(low<=high){
		int mid = (low+high)/2;
		
		if(mid%2==1){
			if(arr[mid]==arr[mid+1])high = mid-1;
			else low = mid+1;
		}else{
			if(arr[mid]==arr[mid+1])low = mid+1;
			else high = mid-1;
		}
	}
	return arr[low];
}