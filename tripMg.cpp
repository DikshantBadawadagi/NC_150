class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        vector<int>ans(3,-1);
        for(auto &it : triplets){
            if(it[0] <= t[0] && it[1] <= t[1] && it[2] <= t[2]){
                ans[0] = max(ans[0],it[0]);
                ans[1] = max(ans[1],it[1]);
                ans[2] = max(ans[2],it[2]);
            }
        }
        return ans == t;

    }
};
