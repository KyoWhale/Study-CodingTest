// 1:23 ~ 1:42

#include <iostream>
#include <algorithm>
using namespace std;

bool sortFunc(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;

    pair<int, int> *meetings = new pair<int, int>[N];
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }
    sort(meetings, meetings+N, sortFunc);

    int count = 0;
    int time = 0;
    for (int i = 0; i < N; i++) {
        if (meetings[i].first >= time) {
            time = meetings[i].second;
            count++;
        }
    }
    cout << count;
}