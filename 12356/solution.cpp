#include <cstdio>

int main() {
    int soldiers, bodies, from, to;

    scanf("%d %d", &soldiers, &bodies);
    while (soldiers != 0 && bodies != 0) {
       
        // Array of soldiers (1 alive, 0 dead)
        int soldierLeft[soldiers+5];
        int soldierRight[soldiers+5];
        for (int i = 0; i < soldiers + 1; i++) {
            soldierLeft[i] = i-1;
            soldierRight[i] = i+1;
        }

        // Algo
        for (int i = 0; i < bodies; i++) {
            scanf("%d %d", &from, &to);
            if (soldierLeft[from] < 1) 
                printf("* ");
            else 
                printf("%d ", soldierLeft[from]);
            if (soldierRight[to] > soldiers)
                printf("*\n");
            else
                printf("%d\n", soldierRight[to]);

            soldierRight[soldierLeft[from]] = soldierRight[to];
            soldierLeft[soldierRight[to]] = soldierLeft[from];

        }

        printf("-\n");
        scanf("%d %d", &soldiers, &bodies);
    }
    return 0;
}
