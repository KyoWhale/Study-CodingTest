#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int> > table(N + 1, vector<int>(N + 1, 0));
    vector<vector<int> > sum(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sum[i][j] = table[i][j]
                    + sum[i-1][j]
                    + sum[i][j-1]
                    - sum[i-1][j-1];
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < M; i++)
    {
        int startX, startY;
        int endX, endY;
        cin >> startX >> startY >> endX >> endY;
        
        int total = sum[endX][endY]
                    - sum[endX][startY-1]
                    - sum[startX-1][endY]
                    + sum[startX-1][startY-1];
        cout << total << "\n";
    }
}