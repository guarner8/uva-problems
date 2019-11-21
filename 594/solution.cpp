#include <cstdio>
#include <bitset>

using namespace std;

int main() {
    int num;
   
    while (scanf("%d", &num) != EOF) {
        int b1 = (num & 0xff) << 24;
        int b2 = (num & 0xff00) << 8;
        int b3 = (num & 0xff0000) >> 8; 
        int b4 = (num & 0xff000000) >> 24; 
        printf("%d converts to %d\n", num,b1 + b2 + b3 + b4);

    }
    
    return 0;
}
