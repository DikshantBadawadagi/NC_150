class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi = INT_MIN;
        int ans =0,l=0,r=0;
        int n = nums.size();
        while(r<n-1){
            for(int i = l;i<=r;i++){
                maxi = max(maxi,i + nums[i]);
            }
            l = r+1;
            r = maxi;
            ans++;
        }
        return ans;
    }
};
