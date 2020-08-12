class Solution {
public:
    bool isAlphanumeric(char c) {      
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) {
            return true;
        }
        
        return false;
    }
    
    bool isPalindrome(string s) {
        const int len = s.length();
  
        int left = 0, right = len - 1;
        
        while (left < right) {
            if (!isAlphanumeric(s.at(left))) {
                left++;
            } else if (!isAlphanumeric(s.at(right))) {
                right--;
            } else if (tolower(s.at(left)) != tolower(s.at(right))) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        
        return true;
    }
};