#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int d, vf, vg;
    while (cin >> d >> vf >> vg) {
        if (vg <= vf) {
            cout << "N\n";
        } else {
            // y1^2 + D^2 = y2^2
            // y1 = v1*t
            // y2 = v2*t
            // t = D/sqrt(v2^2 - v1^2)
            double meet_time = d / sqrt(pow((double)vg, 2) - pow((double)vf, 2));
            double position_at_meet_time = vf * meet_time;
            if (position_at_meet_time <= 12) {
                cout << "S\n";
            } else {
                cout << "N\n";
            }
        }
    }
    return 0;
}
