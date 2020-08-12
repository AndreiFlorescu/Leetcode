class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> answ(n);
        
        answ[0] = 1;
        for (int i = 1; i < n; i++) {
            answ[i] = answ[i - 1] * nums[i - 1];
        }
        
        int r = 1;
        for (int i = n - 2; i >= 0; i--)  {
            r *= nums[i + 1];
            answ[i] *= r;
        }
        
        return answ;
    }
};