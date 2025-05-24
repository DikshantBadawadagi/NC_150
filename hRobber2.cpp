
int rob1(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (int num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>front=nums,back=nums;
        back.pop_back();
        front.erase(front.begin());
        return max({nums[0],rob1(front),rob1(back)});
    }
};
