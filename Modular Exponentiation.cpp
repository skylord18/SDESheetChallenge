#include <bits/stdc++.h>
using namespace std;
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int ans = 1;
	while(n){
		if(n%2==1){
			ans = ans*x;
			ans = ans%m;
			n--;
		}else{
			ans = ans*ans;
			ans = ans%m;
			n/=2;
		}
	}
	return ans%m;
}