class Solution {
    public int maxSubArray(int[] nums) {
        int sol = Integer.MIN_VALUE;
        int cur = 0;
        for (int i : nums) {
            cur += i;
            
            sol = Math.max(cur, sol);
            cur = Math.max(0, cur);
        }
        
        return sol;
    }
}