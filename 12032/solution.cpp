/* 12032 UVA */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int cases, numRungs;
    int max;
    int count, loop, reps;
    long rung[100005];
    vector <long> nakm;
    scanf("%d", &cases);    

    while (cases--) {
        max = 0;
        nakm.clear();
        loop++;

        scanf("%d", &numRungs);
        rung[0] = 0;

        for (int i = 1; i < numRungs + 1; i++) {
            scanf("%ld", &rung[i]);
            int diff = rung[i] - rung[i-1];
            if (max < diff) {
                max = diff;
            }
            nakm.push_back(diff);
        }

        count = max;
        for (int i = 0; i < nakm.size(); i++) {
            if (count == nakm.at(i)) {
                count--;
                continue;
            } else if (count < nakm.at(i)) {
                max++;
                break;
            }
        }

        for (int i = 0; i < numRungs + 1; i++) {
            rung[i] = 0;
        }

        printf("Case %d: %d\n", loop, max);
    }

    return 0;
}
