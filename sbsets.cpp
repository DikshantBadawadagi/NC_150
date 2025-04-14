class Solution {
    private:
    void dp(vector<int>& nums,int ind,vector<int>&temp,vector<vector<int>>&res){
        if(ind >= nums.size()){
            res.push_back(temp);
            return;
        }
        //pick
        temp.push_back(nums[ind]);
        dp(nums,ind+1,temp,res);
        //not pick
        temp.pop_back();
        dp(nums,ind+1,temp,res);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        dp(nums,0,temp,res);

        
        return res;
    }
};
