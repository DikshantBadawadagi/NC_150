class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            int left = 0, right = tails.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tails[mid] < num)
                    left = mid + 1;
                else
                    right = mid;
            }
            if (left < tails.size())
                tails[left] = num;
            else
                tails.push_back(num);
        }
        return tails.size();
    }
};
