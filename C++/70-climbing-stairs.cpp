class Solution {
public:
    int climbStairs(int n) {
       
        if (n == 1) {
            return 1;
        }
        
        if (n == 2) {
            return 2;
        }
        
        int pred1 = 1;
        int pred2 = 2;
        
        for (int i = 3 ; i <= n; i++) {
            int aux = pred2 + pred1;
            pred1 = pred2;
            pred2 = aux;
        }
    
        return pred2;
    }
};