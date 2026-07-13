class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int maxsofar = nums[0];
        int curmin = nums[0];
        int curmax = nums[0];
        for (int x = 1; x < nums.size(); x++) {
            int i = nums[x];
            int new_curmin = min(i, min(curmin * i, curmax * i));
            int new_curmax = max(i, max(curmax * i, curmin * i));
            curmin = new_curmin;
            curmax = new_curmax;
            maxsofar = max(maxsofar, max(curmax, curmin));
        }
        return maxsofar;
    }
};
