// 18:38 ~ 18:58
#include <iostream>
#include <map>
using namespace std;

string order[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, L;
    cin >> K >> L;
    map<string, int> dict;
    for (int l = 0; l < L; l++) {
        string input;
        cin >> input;

        if (dict.find(input) != dict.end()) {
            order[dict[input]] = "-1";
        }
        order[l] = input;
        dict[input] = l;
    }

    int i = 0;
    int k = 0;
    while (i < L && k < K) {
        if (order[i] == "-1") {
            i++;
            continue;
        }
        cout << order[i] << "\n";
        i++;
        k++;
    }
}