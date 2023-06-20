#include <bits/stdc++.h> 
using namespace std;
// vector<int> nextSmallerElement(vector<int> &arr, int n){
//     // Write your code here.
//     vector<int> nse(n,-1);
//     for(int i =0;i<n;i++){
//         for(int j =i+1;j<n;j++){
//             if(arr[j]<arr[i]){
//                 nse[i] = arr[j];
//                 break;
//             }
//         }
//     }
//     return nse;
// }


vector<int> nextSmallerElement(vector<int> &arr, int n){
    // Write your code here.
    stack<int> s;
    vector<int> res(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            res[i]=-1;
        }
        else{
            res[i]=s.top();
        }
        s.push(arr[i]);
    }
    return res;
}