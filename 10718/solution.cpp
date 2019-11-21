#include <cstdio>
#include <bitset>

using namespace std;

int main() {
    unsigned int n, l, u, index, max;
    unsigned int answer;

    while (scanf("%u %u %u", &n, &l, &u) != EOF) {
        answer = 0;
        for (int i = 31; i >= 0; i--) {
            if (answer + (1 << i) - 1 < l) {
                answer = answer | (1 << i);
            } else if ((n & (1 << i)) == 0) {
                if (!(answer + (1 << i) > u)) {
                    answer = answer | (1 << i);
                }
            }
        }
        printf("%u\n", answer);
    } 
    return 0;
}
