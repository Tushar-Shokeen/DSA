//Optimised Soln
import java.util.*;
public class Main {
    static int solve(String str) {

        if(str.length()==0)
             return 0;
        int maxans = Integer.MIN_VALUE;
        Set < Character > set = new HashSet < > ();
        int l = 0;
        for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
        {
            if (set.contains(str.charAt(r))) //if duplicate element is found
            {
                while (l < r && set.contains(str.charAt(r))) {
                    set.remove(str.charAt(l));
                    l++;
                }
            }
            set.add(str.charAt(r));
            maxans = Math.max(maxans, r - l + 1);
        }
        return maxans;
    }

    public static void main(String args[]) {
        String str = "takeUforward";
        System.out.println("The length of the longest substring without repeating 
        characters is " + solve(str));

    }
}




//Better Optimised Soln 
class Solution {
    public int lengthOfLongestSubstring(String str) {
        if(str.length()==0)
             return 0;
        int maxans = Integer.MIN_VALUE;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        
        int l = 0, r= 0;
        int n = str.length();
        while(r < n){
            if(map.containsKey(str.charAt(r)))
                l = Math.max(l, map.get(str.charAt(r)) + 1);
            
            map.put(str.charAt(r), r);        
            maxans = Math.max(maxans, r-l+1);
            r++;
        }
        return maxans;
    }
}
