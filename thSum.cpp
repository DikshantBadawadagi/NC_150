class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>>ans;
            int n = nums.size();
            
            for(int i=0;i<n-2;i++){
                // if( i > 0 && nums[i] == nums[i+1])continue;
                int l = i+1,r= n-1;
                while( l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum == 0){
                        ans.push_back({nums[i], nums[l], nums[r]});
                        while(nums[l] == nums[l+1])l++;
                        while(nums[r] == nums[r-1])r--;
                        l++;
                        r--;
                    }
                    else if(sum >0 ){
                        r--;
                    }
                    else{
                        //sum < 0
                        l++;
                    }
                }
            }
            // vector<vector<int>>res;
            // for(auto v : ans){
            //     res.push_back(v);
            // }
            return ans;
        }
    };
    