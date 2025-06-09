class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(auto num : nums){
            sum += num;
        }
        return n*(n+1)/2 - sum;
    }
};
