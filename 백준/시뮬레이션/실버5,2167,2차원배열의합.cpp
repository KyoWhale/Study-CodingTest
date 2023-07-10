// 14:53 ~ 15:06

#include <iostream>
using namespace std;

int main() {
    int table[301][301] = {0};
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> table[i][j];

    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
        int answer = 0;
        int i, j, x, y;
        cin >> j >> i >> y >> x;

        for (int b = j-1; b < y; b++)
            for (int a = i-1; a < x; a++)
                answer += table[b][a];

        cout << answer << "\n";
    }
}