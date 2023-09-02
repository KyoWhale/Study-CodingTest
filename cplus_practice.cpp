#include <iostream>
#include <vector>

using namespace std;

// 0. #include <bits/stdc++.h> 에는 대부분의 헤더가 포함되어 있음. gcc는 있음
// 1. STL도 함수 인자로 넣으면 복사함
// 2. 공백을 포함한 라인은 getline(string)으로 해야함
// 3. ios::sync_with_stdio(0), cin.tie(0)으로 입출력으로 인한 시간 초과를 막아야함
// 4. endl 절대 쓰지 말 것
// 5. 배열은 algorithm.fill 함수를 이용해 초기화할 수 있음

int main()
{
    vector<int> A;
    
    A.push_back(1);
    A.insert(A.begin(), 7);
    A.insert(A.begin() + 2, 10);

    A[4] = -5;

    A.pop_back();
    // A.erase(A.begin() + 3);
    A.clear();

    A.size();
    A.front();
    A.back();
    A[3];
    // A.at(5);
    A.begin();
    A.end();
}