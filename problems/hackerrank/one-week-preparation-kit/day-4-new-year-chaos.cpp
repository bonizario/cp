#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void update(vector<int> &bit, int n, int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int getSum(vector<int> &bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void minimumBribes(vector<int> q) {
    int n = q.size(), total_bribes = 0, bribes = 0;
    vector<int> bit(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        // Get count of elements smaller than q[i] (Binary Indexed Tree/Fenwick Tree)
        if ((bribes = getSum(bit, q[i] - 1)) > 2) {
            cout << "Too chaotic\n";
            return;
        }
        total_bribes += bribes;
        update(bit, n, q[i], 1);
    }
    cout << total_bribes << "\n";
}

int main() {
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
