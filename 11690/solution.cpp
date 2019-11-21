#include <cstdio>

int sameset(int arr[], int x) {
    if (arr[x] == x) {
        return x;
    } else {
        return sameset(arr, arr[x]);
    }
}

int find() {
    return 0;
}

int main() {
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int n, m, val, friendA, friendB, money = 0;
        int friendsArr [100000];
        int distances [100000];
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            friendsArr[i] = i;
            distances[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            distances[i] = val;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &friendA, &friendB);
            if (sameset(friendsArr, friendA) != sameset(friendsArr, friendB)) {
                friendsArr[sameset(friendsArr, friendA)] = friendB;
            }
        }


        for (int j = 0; j < n; j++) {
            int root = sameset(friendsArr, j);
            if (root != j) {
                distances[root] += distances[j];
                distances[j] = 0;
            }
        }

        int q;
        for (q = 0; q < n; q++) {
            if (distances[q] != 0) {
                printf("IMPOSSIBLE\n");
                break;
            }
        }
        if (q == n) {
            printf("POSSIBLE\n");
        }

    }
    return 0;
}
