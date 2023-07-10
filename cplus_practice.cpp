#include <iostream>
#include <vector>

using namespace std;

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