// 23:26 ~ 23:59
// https://www.acmicpc.net/board/view/85490

#include <iostream>
using namespace std;

int main() {
    string N;
    int numbers[10];
    for (int i = 0; i < 10; i++)
        numbers[i] = 0;

    cin >> N;
    
    string::iterator iter = N.begin();
    for (iter; iter < N.end(); iter++) {
        numbers[int(*iter)-48]++;
    }
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    string result;
    for (int i = 9; i >= 0; i--) {
        string temp = "";
        for (int j = 0; j < numbers[i]; j++)
            temp += to_string(i);
        result += temp;
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        int count = numbers[i];
        while (count > 0) {
            sum += i;
            count--;
        }
    }

    if (numbers[0] == 0 || sum % 3 != 0)
        cout << "-1";
    else
        cout << result;
}