class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 2 && nums[i] <= 0) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == -nums[i]) {
                    sol.push_back({nums[i], nums[l], nums[r]});
                    int tmp = nums[l];
                    while (nums[l] == tmp && l < r) l++;
                    tmp = nums[r];
                    while (nums[r] == tmp && l < r) r--;
                } else if (nums[l] + nums[r] > -nums[i]) {
                    int tmp = nums[r];
                    while (nums[r] == tmp && l < r) r--;
                } else {
                    int tmp = nums[l];
                    while (nums[l] == tmp && l < r) l++;
                }
            }
            i++;
        }
        return sol;
    }
};
