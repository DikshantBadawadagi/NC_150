class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            priority_queue<pair<int,int>> pq;
            int n = nums.size();
            unordered_map<int,int> mp;
            for(int i=0;i<n;i++){
                mp[nums[i]]++;
            }
            for(auto i:mp){
                pq.push({i.second,i.first});
            }
            vector<int> vec;
            while(k--){
                pair<int,int> p = pq.top();
                pq.pop();
                vec.push_back(p.second);
            }
            return vec;
        }
    };
    