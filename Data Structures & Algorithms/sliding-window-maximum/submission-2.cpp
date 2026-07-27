class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> p;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            p.push({nums[i], i});
        }
        res.push_back(p.top().first);
        for (int i = k; i < nums.size(); i++) {
            p.push({nums[i], i});
            while (p.top().second <= i - k) p.pop();
            res.push_back(p.top().first);
        }
        return res;
    }
};
