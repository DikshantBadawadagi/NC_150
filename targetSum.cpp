class Solution {
private:
    int f(int ind, int sum, int target, vector<int>& nums, unordered_map<int, unordered_map<int, int>>& dp) {
        if (ind == nums.size()) {
            return sum == target ? 1 : 0;
        }

        if (dp[ind].count(sum)) return dp[ind][sum];

        int add = f(ind + 1, sum + nums[ind], target, nums, dp);
        int subtract = f(ind + 1, sum - nums[ind], target, nums, dp);

        return dp[ind][sum] = add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, unordered_map<int, int>> dp;
        return f(0, 0, target, nums, dp);
    }
};
