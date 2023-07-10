// 11:57 ~ X 12:59
// https://mjmjmj98.tistory.com/70

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    string input;
    cin >> input;

    int answer = 0;
    int temp = 1;
    for (int i = 0; i < input.length(); i++) {
        if(input[i] == '(') {
            temp *= 2;
            s.push('(');
        }
        else if(input[i] == '[') {
            temp *= 3;
            s.push('[');
        }
        else if(input[i] == ')') {
            if(s.empty() || s.top() != '(') {
                answer = 0;
                break;
            }
            if(input[i-1] == '(') {
                answer += temp;
                temp /= 2;
                s.pop();
            }
            else {
                temp /= 2;
                s.pop();
            }
        }
        else if(input[i] == ']') {
            if(s.empty() || s.top() != '[') {
                answer = 0;
                break;
            }
            if(input[i-1] == '[') {
                answer += temp;
                temp /= 3;
                s.pop();
            }
            else {
                temp /= 3;
                s.pop();
            }
        }
    }

    if(!s.empty()) answer = 0;

    cout << answer;
}