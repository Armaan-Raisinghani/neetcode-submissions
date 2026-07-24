class TimeMap {
   public:
    unordered_map<string, vector<pair<string, int>>> hash;
    TimeMap() { hash = {}; }

    void set(string key, string value, int timestamp) {
        if (!hash.contains(key)) hash[key] = {};
        hash[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        auto v = hash[key];
        int l = 0;
        int r = v.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (timestamp >= v[m].second)
                l = m+1;
            else
                r = m;
        }
        if(l==0) return "";
        else return v[l-1].first;
    }
};
