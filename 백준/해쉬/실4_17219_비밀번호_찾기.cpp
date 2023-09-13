// 19:17 ~ 19:26
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<string, string> sites;
    for (int n = 0; n < N; n++) {
        string s, p;
        cin >> s >> p;
        sites[s] = p;
    }

    for (int m = 0; m < M; m++) {
        string s;
        cin >> s;
        cout << sites[s] << "\n";
    }
}