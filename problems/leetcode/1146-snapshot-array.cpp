class SnapshotArray {
   private:
    vector<vector<pair<int, int>>> arr;
    int current_snap;

   public:
    SnapshotArray(int length) {
        current_snap = 0, arr.resize(length);
        for (auto& element : arr) {
            element.push_back({0, 0});
        }
    }

    void set(int index, int val) {
        if (!arr[index].empty() && arr[index].back().first == current_snap) {
            arr[index].back().second = val;
        } else {
            arr[index].push_back({current_snap, val});
        }
    }

    int snap() {
        current_snap += 1;
        return current_snap - 1;
    }

    int get(int index, int snap_id) {
        int left = 0, right = arr[index].size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (snap_id <= arr[index][mid].first) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (arr[index][left].first > snap_id && left > 0) {
            left -= 1;
        }
        return arr[index][left].second;
    }
};
