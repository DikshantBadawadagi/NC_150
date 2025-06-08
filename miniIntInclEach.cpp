class Solution {
public:
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vii;

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
            int n = intervals.size(), m = queries.size();

    std::vector<std::pair<int,int>> v(m);
    for (int i = 0; i < m; ++i) {
        v[i] = {queries[i],i};
    }
    std::sort(v.begin(),v.end());
    std::sort(intervals.begin(),intervals.end());

    vi ans(m);
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>> pq;

    for (int i = 0, k = 0; k < m; ++k) {
        int s = v[k].first, pos = v[k].second;
        while (i < n && intervals[i][0] <= s) {
            int size = intervals[i][1] - intervals[i][0] + 1;
            pq.push({size, intervals[i][1]});
            ++i;
        }
        while (!pq.empty() && pq.top().second < s) pq.pop();
        ans[pos] = (pq.size()) ? pq.top().first : -1;
    }
    return ans;

        
    }
};
