class Solution {
    public boolean isHappy(int n) {
        boolean[] freq = new boolean[1000];
        
        int cur;
        
        while (true) {
            cur = 0;
            
            while (n != 0) {
                int c = n % 10;
                n /= 10;
                
                cur += c * c; 
            }
            
            if (freq[cur]) {
                return false;
            } else if (cur == 1) {
                return true;
            } else {
                n = cur;
                freq[cur] = true;
            }
        }
    }
}