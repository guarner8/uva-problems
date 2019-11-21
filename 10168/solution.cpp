#include <cstdio>
#include <math.h>

int prime_sieve [10000000]; // 10 Million

void sieve() {
    prime_sieve[0] = 1;
    prime_sieve[1] = 1;
    for (int i = 2; i*i <= 10000000; i++) {
        if (prime_sieve[i] != 1) {
            for (int j = 2; j*i <= 10000000; j++) {
                prime_sieve[j*i] = 1;
            }
        }
    }
}

void findPrime(int prime) {
    int first = 2, second = prime-2, next = 0;
    int flag = 0;

    while (first + second != prime || prime_sieve[first] != 0 || prime_sieve[second] != 0) {
        first++;
        second--;
    }
    printf("%d %d\n", first, second);
}

int main() {
    int prime;

    sieve();    

    while (scanf("%d", &prime) != EOF) {
        if (prime < 8) {
            printf("Impossible.\n");
        } else if (prime % 2 == 0) {
            printf("2 2 ");
            findPrime(prime - 4);
        } else {
            printf("2 3 ");
            findPrime(prime - 5);
        }
        
    }
    return 0;
}
