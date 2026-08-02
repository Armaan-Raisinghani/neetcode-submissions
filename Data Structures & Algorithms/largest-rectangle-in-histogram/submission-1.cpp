class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int m = 0;
        for (int i = 0; i <= heights.size(); i++) {
            while (!s.empty() && (heights.size() == i || heights[s.top()] >= heights[i])) {
                int h = s.top();
                s.pop();
                int l = s.empty() ? -1 : s.top();
                m = max(m, (i - l - 1) * heights[h]);
            }
            s.push(i);
        }
        return m;
    }
};
