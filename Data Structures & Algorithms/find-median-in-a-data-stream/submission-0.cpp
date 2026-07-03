class MedianFinder {
   public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder() {
        max_heap = {};
        min_heap = {};
    }

    void addNum(int num) {
        if (max_heap.empty() || num < max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(num);
        if (max_heap.size() - min_heap.size() == 2) {
            int a = max_heap.top();
            min_heap.push(a);
            max_heap.pop();
        } else if (min_heap.size() - max_heap.size() == 2) {
            int a = min_heap.top();
            max_heap.push(a);
            min_heap.pop();
        }
    }

    double findMedian() {
        cout << min_heap.size();
        cout << max_heap.size();
        if (min_heap.size() > max_heap.size())
            return min_heap.top();
        else if (max_heap.size() > min_heap.size())
            return max_heap.top();
        else
            return ((max_heap.top() + min_heap.top()) / 2.0);
    }
};
