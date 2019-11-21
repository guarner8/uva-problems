#include <cstdio>
#include <string>

int main() {
    int num, next, clowns, max, i, j;

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        max = 0;
        scanf("%d", &clowns);
        for (j = 0; j < clowns; j++) {
            scanf("%d", &next);
            if (next > max) {
                max = next;
            }
        }
        printf("Case %d: %d\n", i+1, max);
    }
    return 0;
}
