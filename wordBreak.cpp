class Solution {
private:
    bool f(int start, unordered_map<string, int>& mpp, string& s,vector<int>&dp) {
        if (start == s.length()) {
            return true;
        }
        if(dp[start] != -1)return dp[start];
        for (auto& st : mpp) {
            string word = st.first;
            int len = word.length();
            if (s.substr(start, len) == word) {
                if (f(start + len, mpp, s,dp)) return dp[start] = true;
            }
        }
        return dp[start] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mpp;
        for (auto& w : wordDict) {
            mpp[w]++;
        }
        vector<int>dp(s.length() +1,-1);
        return f(0, mpp, s,dp);
    }
};
