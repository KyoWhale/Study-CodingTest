#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<int> heights(W);
    for (int i = 0; i < W; i++)
        cin >> heights[i];

    int answer = 0;
    for (int i = 1; i < W-1; i++) {
        int lMax = 0, rMax = 0;
        for (int l = 0; l < i; l++) lMax = max(lMax, heights[l]);
        for (int r = W-1; r > i; r--) rMax = max(rMax, heights[r]);
        answer += max(0, min(lMax, rMax) - heights[i]);
    }

    cout << answer << "\n";
}