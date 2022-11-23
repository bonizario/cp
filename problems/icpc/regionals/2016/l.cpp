#include <bits/stdc++.h>
using namespace std;

const int MAXH = 200;
const int MAXL = 200;
const int POSITIVE_INFINITY = 4e4 + 1;

int h, l, tiles[MAXH][MAXL];

void flood_fill(int i, int j, int current_color, int *area) {
    tiles[i][j] = -1, (*area)++;
    if (i > 0 && tiles[i - 1][j] == current_color) {
        flood_fill(i - 1, j, current_color, area);
    }
    if (i < h - 1 && tiles[i + 1][j] == current_color) {
        flood_fill(i + 1, j, current_color, area);
    }
    if (j > 0 && tiles[i][j - 1] == current_color) {
        flood_fill(i, j - 1, current_color, area);
    }
    if (j < l - 1 && tiles[i][j + 1] == current_color) {
        flood_fill(i, j + 1, current_color, area);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int area, best_area = POSITIVE_INFINITY;
    cin >> h >> l;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            cin >> tiles[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            if (tiles[i][j] != -1) {
                area = 0;
                flood_fill(i, j, tiles[i][j], &area);
                if (tiles[i][j] != 0 && area < best_area) {
                    best_area = area;
                }
            }
        }
    }
    cout << best_area << "\n";
    return 0;
}
