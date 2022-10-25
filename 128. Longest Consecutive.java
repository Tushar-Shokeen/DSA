//Brute Force
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)
            return 0;
        Arrays.sort(nums);
        int count=1, maxcount = 0;
        for(int i=1 ; i<nums.length ; i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1]+1)
                count++;
            else{
                if(count > maxcount)
                    maxcount = count;
                count = 1;
            }
            
        }
        if(count > maxcount)
                maxcount = count;
        return maxcount;
    }
}

//Optimized soln TC-O(3N) SC - O(N)
public static int longestConsecutive(int[] nums) {
        Set < Integer > hashSet = new HashSet < Integer > ();
        for (int num: nums) {
            hashSet.add(num);
        }

        int longestStreak = 0;

        for (int num: nums) {
            if (!hashSet.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (hashSet.contains(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
