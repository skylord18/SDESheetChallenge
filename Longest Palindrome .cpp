bool isPal(string s){
    int i = 0, j = s.length()-1;
    while(i<=j){
        if(s[i++]!=s[j--])return false;
    }
    return true;
}
string longestPalinSubstring(string str){
    // Write your code here.
    string ans  ="";
    if(isPal(str)) return str;
    int n = str.length();
    for(int i =0;i<n;i++){
        for(int j =i;j<n;j++){
            if(isPal(str.substr(i,j))){
                int len = j-i+1;
                if(len>ans.length()){
                    ans = str.substr(i,j);
                }
            }
        }
    }
    return ans;
}