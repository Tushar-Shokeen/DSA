//Optimised soln TC - O(2N) + SC - O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;
        
        int l = 0, r = 0;
        int len = 0;
        set<char> map;
        
        while(l<s.length() && r<s.length()){
            if(!map.empty() && map.find(s[r]) != map.end()){
                while(l<r && map.find(s[r]) != map.end())
                    map.erase(s[l++]);
            }
            else{
                map.insert(s[r++]);
                len  = max(len, r-l);
            }
        }
        return len;
    }
};


//Better Optimised Soln TC- O(N) SC- O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;
        
        int l = 0, r = 0;
        int len = 0;
        unordered_map<char,int> map;
        
        while(r<s.length()){
            if(map.find(s[r]) != map.end()){
                l = max(l, map[s[r]] + 1);
            }
            
            map[s[r]] = r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
