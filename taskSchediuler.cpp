class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(auto c : tasks)count[c - 'A']++;

        int maxf = *max_element(count.begin(),count.end());
        int maxcount = 0;
        for(auto it : count){
            if(it == maxf){
                maxcount++;
            }
        }
        int time = (maxf-1)*(n+1) + maxcount;
        return max((int)tasks.size(),time);
    }
};
