#include <cstdio>

using namespace std;

int find (int friends [], int x) {
    if (friends[x] == x) {
        return x;
    } else {
        return (friends[x] = find(friends, friends[x]));
    }
}

int main() {
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {
        int citizens, pairs, max = 0;
        scanf("%d %d", &citizens, &pairs);

        int friends [30002];
        int counter [30002];

        for (int j = 1; j <= citizens; j++) {
            friends[j] = j;
            counter[j] = 0;
        }

        for (int j = 0; j < pairs; j++) {
            int friendA, friendB;
            scanf("%d %d", &friendA, &friendB);

            int findA = find(friends, friendA);
            int findB = find(friends, friendB);

            if (findA != findB) {
                friends[findA] = findB;
            }
        }
        
        /* Sets the friend count */
        for (int j = 1; j <= citizens; j++) {
            counter[find(friends, j)]++;
        }

        /* Finds max of friend count */
        for (int j = 1; j <= citizens; j++) {
            if (counter[j] > max) {
                max = counter[j];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
