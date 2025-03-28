class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>suf(n,1),pref(n,1);
        for(int i=1;i<n-1;i++){
            pref[i] = nums[i-1] * pref[i-1];
            suf[n-i-1] = suf[n-i] * nums[n-i];
        }
        pref[n-1] = nums[n-2] * pref[n-2];
        suf[0] = suf[1] * nums[1];

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = suf[i] * pref[i];
        }
        return ans;
    }
};