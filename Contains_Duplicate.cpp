// this the most optimal one crazy logic uses a good range filtering, i did using XOR first but failed then did hashtable wasnt optimal 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;

        for(int i = 0; i < n; i++){
            if(nums[i] < mn || nums[i] > mx){
                mx = max(nums[i], mx);
                mn = min(nums[i], mn);
                continue;
            }
            for(int j = 0; j < i; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};
