#include <bits/stdc++.h>
using namespace std;

void remove_car(int start, int end, vector<int>& garage) {
    for (int i = start; i <= end; i++) {
        garage[i] = 0;
    }
}

pair<int, int> park_car(int c, vector<int>& garage, int car_length) {
    for (int start = -1, end = -1, i = 0; i < c; i++) {
        if (garage[i] == 0) {
            if (start == -1) {
                start = end = i;
            } else {
                end++;
            }
        } else {
            start = end = -1;
        }
        if (start != -1 && end - start + 1 == car_length) {
            for (int j = start; j <= end; j++) {
                garage[j] = 1;
            }
            return make_pair(start, end);
        }
    }
    return make_pair(-1, -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    char event;
    int c, n, car_plate, car_length, ans;
    vector<pair<int, int>> cars(10000);
    pair<int, int> interval;
    while (cin >> c >> n) {
        vector<int> garage(c, 0);
        ans = 0;
        while (n--) {
            cin >> event >> car_plate;
            if (event == 'C') {
                cin >> car_length;
                interval = park_car(c, garage, car_length);
                if (interval.first != -1) {
                    cars[car_plate] = interval;
                    ans += 10;
                }
            } else {
                auto [start, end] = cars[car_plate];
                remove_car(start, end, garage);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
