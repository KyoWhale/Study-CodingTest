#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    sort(v.begin(), v.end(), [](auto a, auto b){
        if (a.first < b.first) return true;
        return false;
    });

    int answer = 0;

    int left_x = v[0].first, left_y = v[0].second;
    for (int i = 1; i < N; i++)
    {
        if (left_y <= v[i].second)
        {
            answer += (v[i].first - left_x) * left_y;
            left_y = v[i].second;
            left_x = v[i].first;
        }
    }

    int right_x = v.back().first, right_y = v.back().second;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].second > right_y)
        {
            answer += (right_x - v[i].first) * right_y;
            right_y = v[i].second;
            right_x = v[i].first;
        }
    }

    answer += left_y;
    cout << answer << "\n";
}