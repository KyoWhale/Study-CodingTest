include <iostream>
using namespace std;

int T, N, M, K;

int k_table[51][51] = { 0 };
int weight[51][51] = { 0 };

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void printTable(int table[][51])
{
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void findHighest(int &result)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (weight[i][j] > result)
                result = weight[i][j];
        }
    }
}

void dfs(int x, int y) {
    k_table[y][x] = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (0 > nx || M <= nx || 0 > ny || N <= ny) continue;

        weight[ny][nx] = 0;
    }

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (0 > nx || M <= nx || 0 > ny || N <= ny) continue;

        if (k_table[ny][nx] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        memset(k_table, 0, sizeof(k_table));
        memset(weight, 0, sizeof(weight));
        cin >> M >> N >> K;

        int x, y;
        for (int k = 0; k < K; k++)
        {
            cin >> x >> y;
            k_table[y][x] = 1;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (0 > nx || M <= nx || 0 > ny || N <= ny) continue;

                weight[ny][nx] += 1;
            }
        }

        printTable(k_table);
        printTable(weight);

        int highest = 0;
        findHighest(highest);

        int count = 0;
        for (int h = highest; h >= 1; h--) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (weight[i][j] == h) {
                        dfs(j,i);
                        printTable(k_table);
                        printTable(weight);
                        count++;
                    }
                }
            }
        }

        cout << count;
    }
}