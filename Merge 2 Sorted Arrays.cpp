#include <bits/stdc++.h>
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	vector<int> v;
	for(int i = 0;i<arr1.size();i++){
		if(arr1[i]!=0)v.push_back(arr1[i]);
	}
	for(int i = 0;i<arr2.size();i++){
		if(arr2[i]!=0)v.push_back(arr2[i]);
	}
	sort(v.begin(), v.end());
	return v;
}