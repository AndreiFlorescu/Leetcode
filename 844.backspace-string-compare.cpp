class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int lenS = S.length() - 1, lenT = T.length() - 1;
        int skipS = 0, skipT = 0;
    
        while (lenS >= 0 || lenT >= 0) {
            while (lenS >= 0) {
                if (S.at(lenS) == '#') {
                    skipS++;
                    lenS--;
                } else if (skipS > 0) {
                    skipS--;
                    lenS--;
                } else {
                    break;
                }
            }
            
            while (lenT >= 0) {
                if (T.at(lenT) == '#') {
                    skipT++;
                    lenT--;
                } else if (skipT > 0) {
                    skipT--;
                    lenT--;
                } else {
                    break;
                }
            }
            
            if (lenS >= 0 && lenT >= 0 && S.at(lenS) != T.at(lenT)) {
                return false;
            }
            
            if ((lenS >= 0) != (lenT >= 0))
                return false;
            lenS--;
            lenT--;
        }
        
        return true;
    }
};