#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> pwset(vector<int>set)
{
    //Write your code here
    
    vector<vector<int>> ans;
    
    int pow_set_size = pow(2, set.size());
    int counter, j;
 
    // Run from counter 000..0 to 111..1
    for (counter = 0; counter < pow_set_size; counter++) {
        vector<int> curr;
        for (j = 0; j < set.size(); j++) {
            // Check if jth bit in the counter is set
            // If set then print jth element from set
            if (counter & (1 << j))
                curr.push_back(set[j]);
        }
        ans.push_back(curr);
    }
    
    return ans;
}