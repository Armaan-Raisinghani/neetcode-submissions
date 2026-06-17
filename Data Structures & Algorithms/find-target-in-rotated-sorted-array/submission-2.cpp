class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = (l+r)/2;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        int pivot = l;
        if(target>nums[nums.size()-1]){
            l = 0;r=pivot-1;
        }
        else{
            l=pivot;r=nums.size()-1;
        }
        while (l<r) {
            mid = (l+r)/2;
            if(target>nums[mid]) l = mid+1;
            else r = mid;
        }
        if (nums[l]==target) return l;
        else return -1;
    }
};
