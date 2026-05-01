class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(auto &a:piles) r = max(r,a);
        int m = 0;
        int ma = 0;
        while (l<=r){
            int m = (l+r)/2;
            if (eatInSpeed(piles, m)<=h) {r = m-1;ma = m;}
            else l = m+1; 
        }
        return ma;
    }
    int eatInSpeed(vector<int>& piles, int k){
        int s = 0;
        for(auto &a:piles) s+=a/k +(a%k == 0 ? 0 : 1);
        return s;
    }
};
