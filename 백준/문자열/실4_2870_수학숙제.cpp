// 16:37 ~ 17:27

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string& str1, const string& str2) {
    if (str1.size() == str2.size()) return str1 < str2;
    else return str1.size() < str2.size();
}

int main() {
    int N;
    cin >> N;
    
    vector<string> nums;
    string s;
    for (int n = 0; n < N; n++) {
        cin >> s;
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && !(s[i] >= '0' && s[i] <= '9'))
                i++;

            int j = i+1;
            while (j < s.length() && s[j] >= '0' && s[j] <= '9')
                j++;
            
            if (i >= s.length()) continue;
            
            string num = s.substr(i, j-i);
            while (num.length() >= 2 && num[0] == '0') {
                num.erase(0, 1);
            }
            nums.push_back(num);
            i = j;
        }
    }

    sort(nums.begin(), nums.end(), comp);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << "\n";
    }
}