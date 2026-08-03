class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<pair<bool, bool>>> b(
            heights.size(),
            vector<pair<bool, bool>>(heights[0].size(), {false, false}));

        queue<pair<int, int>> q;

        // Pacific
        for (int j = 0; j < heights[0].size(); j++) {
            if (!b[0][j].first) {
                b[0][j].first = true;
                q.push({0, j});
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            if (!b[i][0].first) {
                b[i][0].first = true;
                q.push({i, 0});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r < heights.size() - 1 &&
                heights[r + 1][c] >= heights[r][c] &&
                !b[r + 1][c].first) {
                b[r + 1][c].first = true;
                q.push({r + 1, c});
            }

            if (r > 0 &&
                heights[r - 1][c] >= heights[r][c] &&
                !b[r - 1][c].first) {
                b[r - 1][c].first = true;
                q.push({r - 1, c});
            }

            if (c < heights[0].size() - 1 &&
                heights[r][c + 1] >= heights[r][c] &&
                !b[r][c + 1].first) {
                b[r][c + 1].first = true;
                q.push({r, c + 1});
            }

            if (c > 0 &&
                heights[r][c - 1] >= heights[r][c] &&
                !b[r][c - 1].first) {
                b[r][c - 1].first = true;
                q.push({r, c - 1});
            }
        }

        // Atlantic
        while (!q.empty()) q.pop();

        for (int j = 0; j < heights[0].size(); j++) {
            if (!b[heights.size() - 1][j].second) {
                b[heights.size() - 1][j].second = true;
                q.push({(int)heights.size() - 1, j});
            }
        }

        for (int i = 0; i < heights.size(); i++) {
            if (!b[i][heights[0].size() - 1].second) {
                b[i][heights[0].size() - 1].second = true;
                q.push({i, (int)heights[0].size() - 1});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r < heights.size() - 1 &&
                heights[r + 1][c] >= heights[r][c] &&
                !b[r + 1][c].second) {
                b[r + 1][c].second = true;
                q.push({r + 1, c});
            }

            if (r > 0 &&
                heights[r - 1][c] >= heights[r][c] &&
                !b[r - 1][c].second) {
                b[r - 1][c].second = true;
                q.push({r - 1, c});
            }

            if (c < heights[0].size() - 1 &&
                heights[r][c + 1] >= heights[r][c] &&
                !b[r][c + 1].second) {
                b[r][c + 1].second = true;
                q.push({r, c + 1});
            }

            if (c > 0 &&
                heights[r][c - 1] >= heights[r][c] &&
                !b[r][c - 1].second) {
                b[r][c - 1].second = true;
                q.push({r, c - 1});
            }
        }

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (b[i][j].first && b[i][j].second)
                    res.push_back({i, j});
            }
        }

        return res;
    }
};