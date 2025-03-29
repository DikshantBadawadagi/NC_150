class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> freq{};
        int rightpoint = 0, leftpoint =0;

        int maxCount = 0;
        int maxLen = 0;


        while(rightpoint < s.size()){

            freq[s[rightpoint] - 'A']++;
            
            maxCount = max(maxCount, freq[s[rightpoint] - 'A']);

            while( rightpoint - leftpoint + 1 - maxCount > k ){
                freq[s[leftpoint] - 'A']--;
                leftpoint++;
            }
            maxLen = max(maxLen, rightpoint - leftpoint + 1);

            rightpoint++;
        }

        return maxLen;
    }
};