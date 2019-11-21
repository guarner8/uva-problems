#include <cstdio>
#include <string>

int main() {
    int length, height, totalHeight, moves, counter; 
    
    scanf("%d", &length);
    while (length != 0) {
        counter++;
        totalHeight = 0;
        moves = 0;
        int heights [length];
        for (int i = 0; i < length; i++) {
            scanf("%d", &heights[i]);
            totalHeight += heights[i];
        }
        totalHeight = totalHeight/length;
        for (int j = 0; j < length; j++) {
            if (heights[j] > totalHeight) {
                moves += (heights[j] - totalHeight);
            }
        }

        printf("Set #%d\n", counter);
        printf("The minimum number of moves is %d.\n\n", moves);
        scanf("%d", &length);
    }
    return 0;
}
