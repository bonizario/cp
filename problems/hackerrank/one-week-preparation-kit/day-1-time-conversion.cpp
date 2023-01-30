#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    int hour = stol(s.substr(0, 2));
    if (s[8] == 'P' && hour < 12) {
        hour += 12;
    } else if (s[8] == 'A' && hour == 12) {
        hour -= 12;
    }
    stringstream ss;
    ss << setw(2) << setfill('0') << hour;
    return ss.str() + s.substr(2, 6);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
