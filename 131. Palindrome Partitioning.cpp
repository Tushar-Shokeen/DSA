class Solution {
    
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
          if (s[start++] != s[end--])
            return false;
        }
        return true;
    }
    
    
    void help(int idx,const int &n, string s, vector<string> &temp, vector<vector<string>> &ans){
        if(idx >= n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                help(i+1,n, s, temp, ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        if(s.length() == 1){
            temp.push_back(s);
            ans.push_back(temp);
            return ans;
        }
        
        help(0,s.length(), s, temp, ans);
        
        return ans;
    }
};
