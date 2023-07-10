// 16:53 ~ 17:01

#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int count = 0;

    int *coins = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    for (int i = N-1; i >= 0; i--) {
        if (K >= coins[i]) {
            count += K / coins[i];
            K = K % coins[i];
        }
    }

    cout << count;
}