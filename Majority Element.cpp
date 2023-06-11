#include <bits/stdc++.h>
using namespace std;
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt = 0, el , i = 0;
	while(i<n){
		if(cnt==0){
			el = arr[i];
			cnt++;
		}else if(el == arr[i]){
			cnt++;
		}else {
			cnt--;
		}
		i++;
	}
	int freq = 0;
	for(int i = 0;i<n;i++){
		if(arr[i]==el)freq++;
	}
	if(freq>n/2)return el;
	else return -1;
}