class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.resize(rowIndex + 1);
        
        vector<int> aux;
        aux.resize(rowIndex + 1);
        
        ans[0] = 1;
        
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    aux[j] = 1;
                } else {
                    aux[j] += ans[j - 1];
                }
            }
            
            ans = aux;
        }
        
        return ans;
    }
};