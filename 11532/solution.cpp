#include <cstdio>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

int getNum(int P, int Q) {
    return P;
}

int main() {
    int C, P, Q;
    scanf("%d", &C);
    while (C--) {
        scanf("%d %d", &P, &Q);
        string str = "";
        str.clear();
        //printf("%d %d\n" , P, Q);
        
        // One in front
        if ( P % 2 == 1 ) { 
            
            if (Q > P / 2) { 
                Q = P / 2; 
                str.push_back('1');
                P--;
            }
            for (int i = 0; i < Q; i++) {
                str += "101";
            }
            for (int q = 0; q < P - 2 * Q; q++) {
                str.push_back('1');
            }
            
        } else {
            if (Q > P / 2) { Q = P / 2; }
           
            for (int i = 0; i < Q; i++) {
                str += "101";
            }
            for (int q = 0; q < P - 2 * Q; q++) {
                str.push_back('1');
            }
        }
        
        char str1 [51];
        strcpy(str1, str.c_str()); 
        char * pend;

        long long pr = strtoull(str1, &pend, 2);
        // stol(str);
        printf("%lld\n", pr);
    }
    return 0;
}
