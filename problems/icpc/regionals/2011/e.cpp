#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    char query;
    int c, n, parked, car_id, car_size, current_end, next_start;
    unordered_map<int, list<pair<int, int>>::iterator> position;
    list<pair<int, int>> parking_lot;

    while (cin >> c >> n) {
        parked = 0;
        position.clear(), parking_lot.clear();
        parking_lot.push_back({0, 0}), parking_lot.push_back({c, c});

        while (n--) {
            cin >> query >> car_id;

            if (query == 'S') {
                parking_lot.erase(position[car_id]);
                continue;
            }

            cin >> car_size;

            // similar to (for int i = 0; i < parking_lot.size() - 1; i++)
            for (auto it = parking_lot.begin(); it != prev(parking_lot.end()); it++) {
                next_start = (*next(it)).first, current_end = (*it).second;
                // if the car fits between current and next intervals
                if (next_start - current_end >= car_size) {
                    // insert the interval before the next interval
                    list<pair<int, int>>::iterator new_position =
                        parking_lot.insert(next(it), {current_end, current_end + car_size});
                    position[car_id] = new_position;
                    parked += 10;
                    break;
                }
            }
        }

        cout << parked << "\n";
    }

    return 0;
}
