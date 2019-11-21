#include <cstdio>
#include <bitset>
#include <list>

using namespace std;

int main() {
    int cases, min, max, prev, maxDistance;
    bitset <10000001> primes;
    bool duplicate;

    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        scanf("%d %d", &min, &max);
        
        primes.reset();

        int distance [1000001] = {0};

        primes.set(0, 1);
        primes.set(1, 1);
        for (int j = 2; j*j <= max; j++) {
            for (int n = 2; n * j <= max; n++) {
                primes.set(j*n, 1);
            }
        }

        maxDistance = 0;
        prev = 0;
        duplicate = false;
        for (int k = min; k <= max; k++) {
            if (primes.test(k) == 0) {
                if (prev == 0) {
                    prev = k;
                } else {
                    distance[k - prev]++;
                    if (distance[k-prev] == distance[maxDistance]) {
                        if (maxDistance == k-prev) {
                            maxDistance = k-prev;
                            duplicate = false;
                        } else {
                            duplicate = true;
                        }
                    }
                    if (distance[k-prev] > distance[maxDistance]) {
                        maxDistance = k-prev;
                        duplicate = false;
                    }
                    prev = k;
                }
            }
        }
        if (maxDistance == 0 || duplicate == true) {
            printf("No jumping champion\n");
        } else {
            printf("The jumping champion is %d\n", maxDistance);
        }
    }
    return 0;
}
