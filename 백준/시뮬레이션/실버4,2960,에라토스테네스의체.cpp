// 15:08 ~ 15:34

#include <iostream>
using namespace std;

int main() {
    int N, K;
    int *dp;

    cin >> N >> K;
    dp = new int[N+1];
    for (int i = 0; i < N+1; i++) 
        dp[i] = 0;

    int count = 0;
    for (int i = 2; i < N+1; i++) {
        if (dp[i] != 0) continue;

        int erase = i;
        int multi = 1;
        while(erase*multi < N+1) {
            if (dp[erase*multi] == 0) {
                dp[erase*multi] = 1;
                count++;
                if (count == K) {
                    cout << erase*multi;
                    break;
                }
            }
            multi++;
        }

    }

    delete dp;
}