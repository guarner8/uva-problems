#include <cstdio>
#include <vector>

int main() {
    const int maxYears = 10000;

    int i, j, numComputers, year, a, b, counter;
    
/* 
*   First twenty indexes are the years, second twenty are their bug, 40 and 41 are the max number's spot.
*/
    int yearList [42];

    scanf("%d", &numComputers);
    while (numComputers != 0) {
        counter++;
        yearList[40] = 0; 
        yearList[41] = 0;
        for (i = 0; i < numComputers; i++) {
            scanf("%d %d %d", &year, &a, &b);

            yearList[i] = year;
            yearList[i+20] = b-a;

            // Update max
            if (year > yearList[40]) {
                yearList[40] = year;
                yearList[41] = yearList[i+20];
            }
        }

        for (j = yearList[40]; j < maxYears; j += yearList[41]) {
            for (i = 0; i < numComputers; i++) {
                if ((j - yearList[i]) % yearList[i+20]) {
                    break;
                }
            }
            if (i == numComputers) {
                break;
            }
        }
        printf ("Case #%d:\n", counter);
        if (j < maxYears) {
            printf("The actual year is %d.\n\n", j);
        } else {
            printf("Unknown bugs detected.\n\n");
        }
        scanf("%d", &numComputers);
    }
    return 0;
}
