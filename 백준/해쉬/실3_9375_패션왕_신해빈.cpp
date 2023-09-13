// 19:27 ~ 
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        map<string, int> clothes;
        for (int n = 0; n < N; n++) {
            string s, p;
            cin >> s >> p;
            
            if (clothes.find(p) != clothes.end()) {
                clothes[p] += 1;
            } else {
                clothes[p] = 1;
            }
        }

        int answer = 1;
        for (auto p : clothes) {
            answer *= (p.second + 1);
        }
        cout << answer - 1 << "\n";
    }
}