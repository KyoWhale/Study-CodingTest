// 24:15 ~ X 25:16

#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (N == 1)
        cout << 1;
    else if (N == 2)
        cout << min(4, (M+1)/2);
    else if (M < 7)
        cout << min(4, M);
    else
        cout << M - 2;
}