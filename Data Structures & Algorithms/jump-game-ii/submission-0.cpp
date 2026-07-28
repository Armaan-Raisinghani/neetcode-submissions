class Solution {
   public:
    int jump(vector<int>& nums) {
        int res = 0;
        int l = 0;
        int r = 0;
        while (r < nums.size() - 1) {
            int f = 0;
            for (int i = l; i <= r; i++) f = max(f, i + nums[i]);
            l = r + 1;
            r = f;
            res++;
        }
        return res;
    }
};
