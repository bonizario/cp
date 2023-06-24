class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }
        const vector<pair<int, string>>& timestamps = m[key];
        int left = 0, right = timestamps.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (timestamp <= timestamps[mid].first) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (timestamp < timestamps[left].first) {
            return left > 0 ? timestamps[left - 1].second : "";
        }
        return timestamps[left].second;
    }
};
