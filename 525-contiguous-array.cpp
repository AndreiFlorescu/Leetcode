class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> fst_oc;
        fst_oc[0] = 0;
        
        for (int i = 0; i < (int) nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        
        int sol = 0;
        int cur = 0;
        
        for (int i = 0; i < (int) nums.size(); i++) {
            cur += nums[i];
        
            auto elem = fst_oc.find(cur);
            
            if (elem != fst_oc.end()) {
                sol = max(sol, i + 1 - fst_oc[cur]);
            } else {
                fst_oc[cur] = i + 1;
            }
        }
        
        return sol;
    }
};