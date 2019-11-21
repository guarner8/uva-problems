#include <cstdio>
#include <queue>
#include <bitset>

using namespace std;

int main() {
    int high, numPrimes, count, toPrint, keeper;
    while (scanf("%d %d", &high, &numPrimes) != EOF) {
        bitset <10000001> primes;
        queue <int> result;
        keeper = numPrimes;
        primes.reset();
        
        for (int j = 2; j*j <= high; j++) {
            for (int n = 2; n * j <= high; n++) {
                primes.set(j*n, 1);
            }
        }

        count = 0;
        for (int j = 1; j <= high; j++) {
            if (primes.test(j) == 0) {
                count++;
                result.push(j);
            }
        }
        
        if (count < 2 * numPrimes) {
            numPrimes = count;
        } else if (count % 2 == 1) {
            numPrimes = 2*numPrimes - 1;
        } else {
            numPrimes = 2*numPrimes;
        }

        count = (count - numPrimes) / 2;
        for (int i = 0; i < count; i++) {result.pop();}

        printf("%d %d: ", high, keeper);
        for (int i = 0; i < numPrimes; i++) {
            toPrint = result.front();
            if (i + 1 == numPrimes) {
                printf("%d\n", toPrint);
            } else {
                printf("%d ", toPrint);
            }
            result.pop();
        }
        printf("\n");
    }
}
