class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size(),l = 0,r = n-1;
    
            while(l < r){
                if(nums[l] + nums[r] > target){
                    r--;
                }
    
                else if(nums[l] + nums[r] < target){
                    l++;
                }
    
                else{
                    return {l + 1,r + 1};
                }
            } 
            
            return {-1, -1};
        }
    };
    