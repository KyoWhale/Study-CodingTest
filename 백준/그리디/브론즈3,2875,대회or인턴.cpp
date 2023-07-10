// 18:56 ~ X 19:46
// https://www.acmicpc.net/board/view/75475

#include <iostream>
using namespace std;

int main() {
    int N,M,K;
    cin>>N>>M>>K;

    cout<< min(min(N/2, M), ((N + M - K) / 3));
}

/*

    if (N >= 2 * M) {
        result = M;
        N -= 2 * M;
        M = 0;
    } else {
        result = N / 2;
        N -= N / 2;
        M -= result;
    }

    K = K - N - M;
    if (K > 0) {
        result -= K / 3 + ((K % 3) == 0 ? 0 : 1);
    }
    
*/