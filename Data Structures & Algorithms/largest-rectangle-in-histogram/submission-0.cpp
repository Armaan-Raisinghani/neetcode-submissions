class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l(heights.size(), -1);
        vector<int> r(heights.size(), heights.size());
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (!s.empty()) l[i] = s.top();
            s.push(i);
        }
        s = stack<int>();
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (!s.empty()) r[i] = s.top();
            s.push(i);
        }
        int m = 0;
        for (int i = 0; i < heights.size(); i++) {
            m = max(m, (r[i] - l[i] - 1) * heights[i]);
        }
        return m;
    }
};
