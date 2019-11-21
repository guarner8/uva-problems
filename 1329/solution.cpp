#include <cstdio>
#include <cstdlib>
#include <string.h>

int sameset(int links[], int x) {
    if (links[x] == x) {
        return x;
    } else {
        return sameset(links, links[x]);
    }
}

int find(int links[], int x) {
    if (links[x] == x) {
        return 0;
    } else {
        int sum = abs(links[x] - x) % 1000 + find(links, links[x]);
        return sum;
    }
}


int main() {
    int cases;
    char str[2];
    scanf("%d", &cases);

    while (cases--) {
        int enterprises;
        scanf("%d", &enterprises);

        int center, link;
        int ans[20005];

        for (int i = 1; i <= enterprises; i++) {
            ans[i] = i;
        }
        //memset(ans, 0, 20005*sizeof(ans[0]));

        while (scanf("%s", str) && str[0] != 'O') {
            if (str[0] == 'I') {
                scanf("%d %d", &center, &link);
                if (sameset(ans, center) != sameset(ans, link)) {
                    ans[center] = link;
                }
            } else if (str[0] == 'E') {
                scanf("%d", &center);
                printf("%d\n", find(ans, center));
            }

        }


    }
    return 0;
}
