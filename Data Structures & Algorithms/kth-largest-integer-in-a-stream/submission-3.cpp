class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> q;
    int m = 0;
    KthLargest(int k, vector<int>& nums) {
        m = k;

        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        if ( q.size()<m || val > q.top()) {
            if (q.size() == m) q.pop();
            q.push(val);
        }
        return q.top();
    }
};
