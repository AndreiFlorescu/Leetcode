class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_with = - 1e9, best_whithout = 0;
        
        for (int x : prices) {
            best_with = max(best_with, best_whithout - x);
            best_whithout = max(best_whithout, best_with + x);
        }
        
        return best_whithout;
    }
};