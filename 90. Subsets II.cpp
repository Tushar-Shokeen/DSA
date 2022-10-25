class Solution {
public:
    void perms(int i, vector<int>& nums,vector<int>& temp, vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        perms(i+1, nums, temp, ans);
        temp.pop_back();
        
        while(i+1<nums.size() && nums[i]==nums[i+1])
            i++;
        perms(i+1, nums, temp, ans);
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        perms(0, nums, temp, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
