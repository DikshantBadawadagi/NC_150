class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1; // base case: 1 way to decode empty string

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0; // '0' can't start a valid decode
            } else {
                dp[i] = dp[i + 1]; // one-digit decode

                if (i + 1 < n) {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (num >= 10 && num <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
    }
};
