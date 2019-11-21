#include <cstdio>

long categories[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long change[300005] = {0};
long in; 

int main() {
    double amount;
    long max = 0;
    long prev = 0;
    
    change[0] = 1;

    for (int i = 0; i < 11; i++) {
        for (int j = categories[i]; j <= 300000; j++) {
            change[j] += change[j - categories[i]];
        }
    }

    scanf("%lf", &amount);
    while (amount != 0.00) {

        in = amount * 100 + .5;

        // Write program here
        printf("%6.2f %16ld\n", amount, change[in]);

        scanf("%lf", &amount);
    }
    return 0;
}
