class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n = temp.size();
        st.push(n-1);

        vector<int>ans;
        ans.push_back(0);

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temp[st.top()] <= temp[i])st.pop();
            if(st.empty())ans.push_back(0);
            else ans.push_back(st.top() - i);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
