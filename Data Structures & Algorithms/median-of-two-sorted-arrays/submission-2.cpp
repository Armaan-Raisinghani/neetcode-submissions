class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int total = nums1.size() + nums2.size();
        int left = total - total / 2;
        int l = 0;
        int r = nums1.size();
        while (l <= r) {
            int m = (l + r) / 2;
            int l1 = (m == 0) ? INT_MIN : nums1[m - 1];
            int r1 = (m == nums1.size()) ? INT_MAX : nums1[m];
            int l2 = (left - m == 0) ? INT_MIN : nums2[left - m - 1];
            int r2 = (left - m == nums2.size()) ? INT_MAX : nums2[left - m];
            if (l1 > r2)
                r = m-1;
            else if (l2 > r1)
                l = m+1;
            else {
                if (total % 2 != 0)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
    }
};
