#include <cstdio>
#include <bitset>

using namespace std;

int main() {
   int cases, missing, sizeIn, position;


    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        int result = 0;
        scanf("%d %d", &sizeIn, &missing);

        bitset<1024> participants;
        participants.set();
        
        for (int j = 0; j < missing; j++) {
            scanf("%d", &position);
            participants.flip(position-1);
        }

        while (sizeIn > 0) {
            for (int q = 0; q < 1 << sizeIn; q += 2) {
                if (participants.test(q) ^ participants.test(q+1)) {
                    participants.set(q / 2, true);
                    result++;
                } else {
                    if (participants.test(q) == 0) {
                        participants.set(q / 2, false);
                    } else {
                        participants.set(q / 2, true);
                    }
                }
            }
            sizeIn--;
        }

        printf("%d\n", result);
    }


    return 0;
}
