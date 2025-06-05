class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& t) {
        vector<vector<int>>res;
        int i=0,n = intervals.size();
        if(n == 0){res.push_back(t);return res;}

        while(i < n){
            while(i < n && intervals[i][1] < t[0]){
                res.push_back(intervals[i]);
                i++;
            }
            while(i < n && (t[0] <= intervals[i][1] && t[1] >= intervals[i][0] )){
                t[0] = min({intervals[i][0],t[0],t[0]});
                t[1] = max({intervals[i][1],t[1],t[1]});
                i++;
            }
            res.push_back(t);
            while( i< n && intervals[i][0] > t[1]){
                res.push_back(intervals[i]);
                i++;
            }
        }
        return res;
    }
};
