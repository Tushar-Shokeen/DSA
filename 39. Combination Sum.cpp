class Solution {
public:
    
    void cSum(int i, int sum,int target,const vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans){
        
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(i >= candidates.size() || sum > target) return;
        
        temp.push_back(candidates[i]);
        sum += candidates[i];
        cSum(i, sum, target, candidates, temp, ans);
        
        temp.pop_back();
        sum -= candidates[i];
        cSum(i+1, sum, target, candidates, temp, ans);
          
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum=0;
        
        cSum(0,sum,target, candidates, temp, ans);
        return ans;
    }
};
