class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cntr = 0;
        
        while (m && n) {
            if (m == n) {
                return m << cntr;
            }
            
            m >>= 1;
            n >>= 1;
            cntr++;
        }
        
        return 0;
    }
};