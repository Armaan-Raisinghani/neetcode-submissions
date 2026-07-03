class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](vector<int> a, vector<int> b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> q(comp);
        for (vector<int> x : points) {
            if (q.size() < k) {
                q.push(x);
            }
            else if (q.size() == k and comp(x, q.top())) {
                q.pop();
                q.push(x);
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};