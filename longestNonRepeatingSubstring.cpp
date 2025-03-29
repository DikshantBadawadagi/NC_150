class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int res = 0;
        vector<int> h(128, 0); 
        int uniqueCount = 0; 

        while (j < n) {
            if (h[s[j]] == 0) 
                uniqueCount++; 
            h[s[j]]++;
            j++;

            if (uniqueCount == j - i) { 
                res = max(res, j - i);
            } else { 
                h[s[i]]--;
                if (h[s[i]] == 0) 
                    uniqueCount--; 
                i++;
            }
        }
        return res;
    }
};