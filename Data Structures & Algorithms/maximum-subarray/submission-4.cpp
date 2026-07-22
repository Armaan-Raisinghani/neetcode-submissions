class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int curmax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curmax = max(curmax+nums[i],nums[i]);
            maxsum = max(curmax, maxsum);
        }
        return maxsum;
    }
};
