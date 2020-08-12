class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for (string s : strs) {
            string s_copy = s;
            sort(s_copy.begin(), s_copy.end());
            m[s_copy].push_back(s);
        }
        vector<vector<string>> sol;
        
        for (auto p : m) {
            sol.push_back(p.second);
        }
        
        return sol;
    }
};