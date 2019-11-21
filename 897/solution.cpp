#include <cstdio>

int an []= {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};

int main() {
    int prime;
    scanf("%d", &prime);
    //printf("%d %d %d\n", an[4], an[13], an[14]);
    while (prime != 0) {
        int i = 0;
        int flag = 0;
        if (prime < 10) {
            for (i = 0; i < 4; i++) {
                if (an[i] > prime) {
                    printf("%d\n", an[i]);
                    break;
                }
            }
            if (i == 4) {flag = 1;}
                
        } else if (prime < 100) {
            for (i = 4; i < 13; i++) {
                if (an[i] > prime) {
                    printf("%d\n", an[i]);
                    break;
                }
            }
            if (i == 13) {flag = 1;}
        } else if (prime < 1000) {
            for (i = 13; i < 22; i++) {
                if (an[i] > prime) {
                    printf("%d\n", an[i]);
                    break;
                }
            }
            if (i == 22) {flag = 1;}
        } else {
            flag = 1;
        }
       
        if (flag == 1) {
            printf("0\n");
        }
        scanf("%d", &prime);
    }
    return 0;
}
