class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)return stones[0];
        if(stones.size() == 2)return abs(stones[0] - stones[1]);
        priority_queue<int,vector<int>>pq;
        for(auto &it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            int top = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if(top == top2)continue;
            else pq.push(abs(top-top2));
        }
        pq.push(0);
        return pq.top();
    }
};
