class Solution {
    private:
    int f(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        if(ind1 >= s1.length() || ind2 >= s2.length()){
            return 0;
        }
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + f(ind1 +1,ind2 +1,s1,s2,dp);
        }
        else return dp[ind1][ind2] = max(f(ind1 +1,ind2,s1,s2,dp),f(ind1,ind2+1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return f(0,0,text1,text2,dp);
    }
};
