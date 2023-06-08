#include <bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	// Write your code here 
	long long int sum = n*(n+1)/2,sqrSum = n*(n+1)*(2*n+1)/6, sumArray = 0, SumArrSqr = 0;
	for(int i = 0;i<arr.size();i++){
		sumArray+=arr[i];
		SumArrSqr+=((long long int)arr[i] * (long long int)arr[i]);
	}
	long long int val1 = sumArray - sum;
	long long int val2 = SumArrSqr - sqrSum;
	long long int xPlusy = val2/val1;
	long long int missing = (val1 +xPlusy)/2;
	long long int repeating = xPlusy - missing;
	return {(int)repeating, (int)missing};
}
