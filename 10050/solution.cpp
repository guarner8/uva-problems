#include <cstdio>

int main() {
    int tests, days, parties, result;

    scanf("%d", &tests);

    for (int i = 0; i < tests; i++) {
        scanf("%d %d", &days, &parties);
        int strikes[parties];
        result = 0;
        for (int j = 0; j < parties; j++) {
            scanf("%d", &strikes[j]);
        }

        for (int q = 0; q < days; q++) {
            if (q % 7 < 5) {
                for (int j = 0; j < parties; j++) {
                    if ((q+1) % strikes[j] == 0) {
                        result++;
                        
                        break;
                    }
                }
            }
        }
        printf("%d\n", result);
    }
    
    return 0;
}
