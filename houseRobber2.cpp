class Solution {
    private:
    int f(int n,vector<int>&nums,vector<int>&dp){
        for(int ind = 1;ind<=n;ind++){
            //pick
            int pick = INT_MIN;
            if(ind != 1)pick = nums[ind] + dp[ind-2];

        //not pick
            int npick = 0 + dp[ind -1];

            dp[ind] = max(pick,npick);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {

        vector<int>dp(nums.size() +1,-1);
        vector<int>dp2(nums.size() +1,-1);


        dp[0] = nums[0];
        dp2[0]=nums[0];

        
        if(nums.size() == 1)return nums[0];
        if(nums.size() ==2)return max(nums[0],nums[1]);
        int fs = f(nums.size()-2,nums,dp);
        nums.erase(nums.begin());
        int ls = f(nums.size()-1,nums,dp2);
        return max(fs,ls);
    }
};
