#include <iostream>
using namespace std;

// 내 풀이
// int main()
// {
//     int N, M;
//     cin >> N >> M;
    
//     int* array = new int[N+1];
//     for (int i = 1; i <= N; i++)
//     {
//         cin >> array[i];
//     }
//     long long* sum = new long long[N+1];
//     for (int i = 1; i <= N; i++)
//     {
//         sum[i] = 0;
//     }
//     sum[1] = array[1];
//     for (int i = 1; i <= N; i++)
//     {
//         sum[i] = sum[i-1] + array[i];
//     }
//     // for (int i = 1; i <= N; i++)
//     // {
//     //     cout << sum[i] << " ";
//     // }

//     for (int i = 0; i < M; i++)
//     {
//         int start, end;
//         cin >> start >> end;

//         cout << sum[end] - sum[start-1] << "\n";
//     }
// }

// 책 풀이
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int suNo, quizNo;
    cin >> suNo >> quizNo;
    int S[100001] = {};

    for (int i = 1; i<= suNo; i++)
    {
        int temp;
        cin >> temp;
        S[i] = S[i-1] + temp;
    }
    for (int i = 0; i < quizNo; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start-1] << "\n";
    }
}