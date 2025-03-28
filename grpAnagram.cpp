class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mpp;
            vector<vector<string>> ans;
    
            for(int i = 0; i < strs.size(); i++) {
                string t = strs[i];
                sort(t.begin(), t.end());
                mpp[t].push_back(strs[i]);
            }
            for (auto& val : mpp) {
                ans.push_back(val.second);
            }
            return ans;
        }
    };
    