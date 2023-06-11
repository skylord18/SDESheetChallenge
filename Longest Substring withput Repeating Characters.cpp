#include <bits/stdc++.h> 
using namespace std;
int uniqueSubstrings(string input){
   int maxAns = INT_MIN,l=0;
   set<int>s;
   for(int r =0;r<input.length();r++){
     if(s.find(input[r])!=s.end()){
        while(l<r && s.find(input[r])!=s.end()){
            s.erase(input[l]);
            l++;
        }
     }
     s.insert(input[r]);
     maxAns = max(maxAns,r-l+1);
   }
   return maxAns;
}