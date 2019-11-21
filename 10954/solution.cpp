#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct myComparator {
    bool operator() (const int &a, const int &b) {
        return a > b;
    }
};

int main() {
    int num;
    int next;

    scanf("%d", &num);
    while(num != 0) {
        priority_queue <int, vector<int>, myComparator> res;
        for (int i = 0; i < num; i++) {
            scanf("%d", &next);
            res.push(next);
        }

        int finalCost = 0;
        int first;
        int second;
        while (res.size() > 1) {
            first = res.top();
            res.pop();
            second = res.top();
            res.pop();
            finalCost += first+second;
            res.push(first+second);
        }

        printf("%d\n", finalCost);
        scanf("%d", &num);
    }

}
