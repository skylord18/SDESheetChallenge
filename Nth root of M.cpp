#include <bits/stdc++.h> 
using namespace std;
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 0, high = m-1;
  while(low<=high){
    int mid = (low+high)/2;
    if(pow(mid,n)==m)return mid;
    else if(pow(mid,n)>m)high = mid-1;
    else low = mid+1;
  }
  return -1;
}