//Brute Force TC - O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        for(int i=0; i<nums.size()-1;i++)
        {
            for(int j=i+1 ; j<nums.size(); j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};


//Better Soln Tc- O(N) SC - O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(map.find(target - nums[i]) != map.end()){
                ans.push_back(map[target - nums[i]]);
                 ans.push_back(i);
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};


