class Solution {
public:
    unordered_map<string, vector<string>> dp;
    
    vector<string> wordBreakAux(string s, vector<string>& wordDict) {
        
        if (s.empty()) {
            return {""};
        }
        
        if (dp.find(s) != dp.end()) {
            return dp[s];
        }
        
        vector<string> curSolution, nextSolution;
        
        for (string word : wordDict) {
            if (s.find(word) == 0) {
                nextSolution = wordBreakAux(s.substr(word.length()), wordDict);
                
                for (string sol : nextSolution) {
                    string space = sol.empty() ? "" : " ";
                    curSolution.push_back(word + space + sol);
                }
            }
        }
        
        dp[s] = curSolution;
        
        return dp[s];
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return wordBreakAux(s, wordDict);
    }
};