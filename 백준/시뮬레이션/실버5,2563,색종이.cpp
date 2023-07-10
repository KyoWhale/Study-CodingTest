// 14:21 ~ 14:51

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int table[101][101] = {0};
    int count = 0; // 초기화 안해줘서 틀림

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;

        for (int y = Y; y < Y+10; y++) {
            for (int x = X; x < X+10; x++) {
                table[y][x]++;
            }
        }
    }

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (table[i][j] != 0)
                count++;
        }
    }   

    cout << count;
}