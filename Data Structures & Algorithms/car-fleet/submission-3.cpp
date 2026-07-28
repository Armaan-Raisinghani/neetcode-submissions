class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        vector<float> res;
        for (int i = 0; i < v.size(); i++) {
            float time = (float)(target - v[i].first) / v[i].second;
            res.push_back(time);
        }
        int f = 0;
        float currmax = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] > currmax) {
                f++;
                currmax = res[i];
            }
        }
        return f;
    }
};
