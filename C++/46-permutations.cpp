class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        
        solve(nums, 0, sol);
        
        return sol;
    }
    
    void swap (int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    
    void solve (vector<int>& nums, int cursor, vector<vector<int>>& sol) {
        if (cursor == nums.size()) {
            sol.push_back(nums);
            return;
        }
        
        for (int i = cursor; i < nums.size(); i++) {
            swap(nums[cursor], nums[i]);
            
            solve(nums, cursor + 1, sol);
            
            swap(nums[cursor], nums[i]);
        } 
    }
};