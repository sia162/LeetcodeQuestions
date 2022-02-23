class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<float,float>> vm;
        
        for(int i=0;i<n;i++) vm.push_back({position[i],speed[i]});
        sort(vm.begin(),vm.end(),std::greater<>());
        
        int fleet = n;
        float SlowestTimeToFinish = 0;
        for(const auto [Pos, Speed]: vm) {
            const float ttf = (target - Pos) / Speed;
            ttf > SlowestTimeToFinish ? SlowestTimeToFinish = ttf : --fleet;
        }

        return fleet;
    }
};