class Solution {
    public:
        bool isPossible(int k, vector<int>& piles, int h){
                int cnt = 0;
                for(int i=0; i<piles.size(); i++){
                    cnt += (piles[i] + k - 1)/k;
                }
                if(cnt>h){
                    return false;
                }
                return true;
            }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            
            int s = 1;
            int e = *max_element(piles.begin(), piles.end());
            int mid = (e-s)/2 + s;
    
            while(s<e){
                if(isPossible(mid, piles, h)){
                    e = mid;
                }
                else{   
                    s = mid + 1;
                }
                mid = (e-s)/2 + s;
            }
            return mid;
        }
    };