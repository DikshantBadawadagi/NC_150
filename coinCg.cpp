class Solution {
    private:
    int f(int ind,int t,vector<int>nums,int n,vector<vector<int>>&dp){
        if(ind == 0){
            if(t%nums[0] == 0){
                return 1;
            }
            else return 0;
        }
        if(t == 0)return 1;

        if(dp[ind][t] != -1)return dp[ind][t];

        int pick =0;
        if(t >= nums[ind]){
            pick = f(ind,t- nums[ind],nums,n,dp);
        }
        int notPick = f(ind-1,t,nums,n,dp);

        return dp[ind][t] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,nums,n,dp);
    }
};
