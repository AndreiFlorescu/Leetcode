class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int paper_no = citations.size();
        
        vector<int> count;
        count.resize(paper_no + 2, 0);
        
        for (int cit : citations) {
            count[min(cit, paper_no)]++;
        }
        
        int h;
        for (h = paper_no; h >= 0; h--) {
            count[h] += count[h + 1];
            
            if (count[h] >= h) {
                break;
            }
        }
        
        return h;
    }
};

class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        
        int ans = 0;
        for (int cit : citations) {
            if (cit >= ans + 1) {
                ans++;
            }
        }
        
        return ans;
    }
};