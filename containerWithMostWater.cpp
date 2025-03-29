class Solution {
    public:
        int maxArea(vector<int>& height) {
            if(height.size()<=1)
                return 0;
            int n = height.size();
            int l =0;
            int r = n-1;
            int area =0;
            while(l<r){
                int h = min(height[l], height[r]);
                int curArea = (r-l)*h;
                area = max(area, curArea);
                if(height[l]<height[r]){
                    l++;
                }
                else
                    r--;
            }
            return area;
        }
    };