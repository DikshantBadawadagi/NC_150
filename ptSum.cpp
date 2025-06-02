class Solution {
private:
    int f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2; // pick or not pick zero
            if (target == 0 || nums[0] == target) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notPick = f(ind - 1, target, nums, dp);
        int pick = 0;
        if (nums[ind] <= target)
            pick = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if ((tot - target) < 0 || (tot - target) % 2 != 0) return 0;
        int t = (tot - target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(t + 1, -1));
        return f(nums.size() - 1, t, nums, dp);
    }
};
