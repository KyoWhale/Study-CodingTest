#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int max = 0;
    float total = 0;
    int* arr = new int[N]();
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        total += arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    float average = (total / max * 100) / N;
    cout << average;
}