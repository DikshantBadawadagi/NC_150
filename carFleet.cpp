class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> pos_speed;
        for (int i = 0; i < position.size(); i ++){
            pos_speed.push_back(std::make_pair(position[i], speed[i]));
        }
        int ans = 0;
        std::sort(pos_speed.begin(), pos_speed.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first > b.first;
});;
        double max_time = 0;
        for (auto x: pos_speed){
            float current_time = static_cast<float>(target - x.first) / x.second;
            if(current_time > max_time){
                ans += 1;
                max_time = current_time;
            }
        }
        return ans;
    }
};