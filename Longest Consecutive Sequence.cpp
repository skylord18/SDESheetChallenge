#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int longestStreak=0;
    set<int>st;
    for(auto it : arr)st.insert(it);
    for(auto it : st){
        if(st.find(it-1)==st.end()){
            int currStreak = 1;
            int currNumber = it;
            while(st.find(currNumber+1)!=st.end()){
                currNumber++;
                currStreak++;
            }
            longestStreak = max(longestStreak, currStreak);
        }
    }
    return longestStreak;
}

// Another Better Approach
// #include <bits/stdc++.h>
// using namespace std;
// int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
//     sort(arr.begin(),arr.end());
//     int maxLength = 0;
//     int count = 1;
//     for(int i = 1; i < n; i++)
//     {
//         if(arr[i]==arr[i-1])
//             continue;
//         else if(arr[i] == arr[i-1]+1)
//             count++;
//         else{
//             maxLength = max(maxLength, count);
//             count = 1;
//         }
//     }
//     maxLength = max(maxLength, count);
//     return maxLength;
// }