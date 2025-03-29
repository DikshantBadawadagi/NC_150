class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int l =0 ,r=n-1;
            int leftm = 0,rightm = 0;
            int ans=0;
    
            while(l <= r){
                if(height[l] <= height[r]){
                    if(height[l] >= leftm){
                        leftm = height[l];
                    }
                    else{
                        ans+=leftm - height[l];
                    }
                    l++;
                }else{
                    if(height[r] >= rightm){
                        rightm = height[r];
                    }else{
                        ans+=rightm - height[r];
                    }
                    r--;
                }
            }
            return ans;
        }
    };
    