class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<pair<bool, bool>>> b(
            heights.size(), vector<pair<bool, bool>>(heights[0].size(), {false, false}));
        queue<vector<int>> q;
        for (int j = 0; j < heights[0].size(); j++) {
            q.push({0, j});
        }
        for (int i = 0; i < heights.size(); i++) {
            q.push({i, 0});
        }
        while (!q.empty()) {
            vector<int> tmp = q.front();
            q.pop();
            if (!b[tmp[0]][tmp[1]].first) {
                b[tmp[0]][tmp[1]].first = true;

                if (tmp[0] < heights.size() - 1 &&
                    heights[tmp[0] + 1][tmp[1]] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0] + 1][tmp[1]].first)
                    q.push({tmp[0] + 1, tmp[1]});

                if (tmp[0] > 0 && heights[tmp[0] - 1][tmp[1]] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0] - 1][tmp[1]].first)
                    q.push({tmp[0] - 1, tmp[1]});

                if (tmp[1] < heights[0].size() - 1 &&
                    heights[tmp[0]][tmp[1] + 1] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0]][tmp[1] + 1].first)
                    q.push({tmp[0], tmp[1] + 1});

                if (tmp[1] > 0 && heights[tmp[0]][tmp[1] - 1] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0]][tmp[1] - 1].first)
                    q.push({tmp[0], tmp[1] - 1});
            }
        }

        while (!q.empty()) q.pop();
        for (int j = 0; j < heights[0].size(); j++) q.push({(int)heights.size() - 1, j});
        for (int i = 0; i < heights.size(); i++) q.push({i, (int)heights[0].size() - 1});

        while (!q.empty()) {
            vector<int> tmp = q.front();
            q.pop();

            if (!b[tmp[0]][tmp[1]].second) {
                b[tmp[0]][tmp[1]].second = true;

                if (tmp[0] < heights.size() - 1 &&
                    heights[tmp[0] + 1][tmp[1]] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0] + 1][tmp[1]].second)
                    q.push({tmp[0] + 1, tmp[1]});

                if (tmp[0] > 0 && heights[tmp[0] - 1][tmp[1]] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0] - 1][tmp[1]].second)
                    q.push({tmp[0] - 1, tmp[1]});

                if (tmp[1] < heights[0].size() - 1 &&
                    heights[tmp[0]][tmp[1] + 1] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0]][tmp[1] + 1].second)
                    q.push({tmp[0], tmp[1] + 1});

                if (tmp[1] > 0 && heights[tmp[0]][tmp[1] - 1] >= heights[tmp[0]][tmp[1]] &&
                    !b[tmp[0]][tmp[1] - 1].second)
                    q.push({tmp[0], tmp[1] - 1});
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (b[i][j].first && b[i][j].second) res.push_back({i, j});
            }
        }
        return res;
    }
};
