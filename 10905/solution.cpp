/* UVa 10905 Children's Game */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool myComparator(const string &str1, const string &str2) {
    return str1 + str2 < str2 + str1;
}

int main() {
    int index;
    string result, next;
    vector <string> nums;

    scanf("%d", &index);
    while (index != 0) {   
        for (int i = 0; i < index; i++) {
            cin >> next;
            nums.push_back(next);
        }

        sort(nums.begin(), nums.end(), myComparator);
        result = "";

        for (int j = index; j > 0; j--) {
            result += nums.back();
            nums.pop_back();
        }

        printf("%s\n", result.c_str());
        scanf("%d", &index);
    }
    return 0;
}
