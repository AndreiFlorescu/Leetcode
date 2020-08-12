class Solution {
    public void moveZeroes(int[] nums) {
        int pos = 0;
        
        for (int n : nums) {
            if (n != 0) {
                nums[pos] = n;
                pos += 1;
            }
        }
        
        for (int i = pos; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}