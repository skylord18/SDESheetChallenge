#include <bits/stdc++.h> 
using namespace std;
bool isPal(string s){
	int start = 0, end = s.length()-1;
	while(start<=end){
		if(s[start++]!=s[end--])return false;
	}
	return true;
}
// int minCharsforPalindrome(string str) {
// 	// Write your code here.
// 	int cnt = 0;
// 	if(isPal(str))return 0;
// 	for(int i = str.length()-1;i>=0;i--){
// 		cnt++;
// 		if(isPal(str.substr(0,i)))break;
// 	}
// 	return cnt;
// }
int minCharsforPalindrome(string str) {
	int n = str.size();
	int i = 0, j = n - 1, count = 0, tempJ = j;
	while(i < j) {
		if(str[i] == str[j])
			i++, j--;
		else {
			count++;
			i = 0, tempJ--;
			j = tempJ;
		}
	}	
	return count;
}