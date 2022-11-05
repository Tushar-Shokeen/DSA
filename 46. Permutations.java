class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();

        perm(0, nums, ans);
        return ans;
    }

    public void perm(int pos, int[] nums, List<List<Integer>> ans){
        if(pos == nums.length){
            List<Integer> temp = new ArrayList<>();
            for(int i=0; i<nums.length; i++){
                temp.add(nums[i]);
            }
            ans.add(temp);
            return;
        }

        for(int i = pos; i<nums.length; i++){
            swap(nums, i, pos);
            perm(pos+1, nums, ans);
            swap(nums, i, pos);
        }
    }

    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
