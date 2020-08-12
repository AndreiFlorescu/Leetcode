class Solution {
public:
    bool canJump(vector<int>& nums) {       
        const int len = nums.size();
        int reachable = 0;
        
        for (int i = 0; i <= reachable; i++) {
            if (i == len - 1) {
                return true;
            }
            
            reachable = max(reachable, i + nums[i]);
        }
        return false;
    }
};