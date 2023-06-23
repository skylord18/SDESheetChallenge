#include <bits/stdc++.h> 
using namespace std;
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    map<char, int> mp1,mp2;
    if(str1.length()!=str2.length())return false;
    for(int i =0;i<str1.length();i++){
        mp1[str1[i]]++;
    }
    for(int i =0;i<str2.length();i++){
        mp2[str2[i]]++;
    }
    return mp1==mp2;
}