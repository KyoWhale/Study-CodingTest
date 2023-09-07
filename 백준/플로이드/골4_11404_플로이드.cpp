// 18:35 ~ 
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int table[101][101];

int main() {
    // ios::sync_with_stdio;
    cin.tie();

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fill(table[i], table[i]+n+1, INF);

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        table[start][end] = min(table[start][end], cost);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                table[i][j] = min(table[i][k] + table[k][j], table[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (table[i][j] == INF)
                cout << 0 << " ";
            else
                cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}