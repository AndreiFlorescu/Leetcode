class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int left = 1;
        int right = num;
        int mid;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            long long pow = 1LL * mid * mid;
            
            if (pow == num) {
                return true;
            } else if (pow < num) {
                left = mid + 1;
            } else if (pow > num) {
                right = mid - 1;
            }
        }
        
        return false;
    }
};