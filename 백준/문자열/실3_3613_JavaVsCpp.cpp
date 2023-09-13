// 12:50 ~ 13:10

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s[0] == '_' || s[s.length()-1] == '_') {
        cout << "Error!";
        return 0;
    }
    if (s[0] >= 'A' && s[0] <= 'Z') {
        cout << "Error!";
        return 0;
    }

    bool isCpp = false;
    bool hasCap = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
            if (i > 0 && s[i-1] == '_') {
                cout << "Error!";
                return 0;
            }
            isCpp = true;
        }

        if (s[i] >= 'A' && s[i] <= 'Z') {
            hasCap = true;
        }
    }

    if (isCpp && hasCap) {
        cout << "Error!";
        return 0;
    }

    string newS = "";
    if (hasCap) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                newS += '_';
                newS += s[i] - 'A' + 'a';
            } else {
                newS += s[i];
            }
        }

        cout << newS;
        return 0;
    }

    bool isPrevUnderbar = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
            isPrevUnderbar = true;
        }
        else if (isPrevUnderbar) {
            newS += s[i] - 'a' + 'A';
            isPrevUnderbar = false;
        }
        else {
            newS += s[i];
        }
    }

    cout << newS;
}