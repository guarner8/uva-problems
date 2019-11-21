#include <cstdio>
#include <string>

using namespace std;

int b[3];
int g[3];
int c[3];

// Water bottle order is B G C
// Let first index represent B, second G, third C

int calculateCost(int a, int d, int e) {
    int cost = 0;
    if (a == 0) {
        cost += b[1] + b[2];
        if (d == 1) { // B, G, C
            cost += g[0] + g[2] + c[1] + c[0];
            //printf("BGC cost: %d\n", cost);
        } else {      // B, C, G
            cost += g[0] + g[1] + c[2] + c[0];
            //printf("BCG cost: %d\n", cost);
        }
    } else if (a == 1) {
        cost += b[0] + b[2];
        if (d == 0) { // G, B, C
            cost += g[1] + g[2] + c[1] + c[0];
            //printf("GBC cost: %d\n", cost);
        } else {      // C, B, G
            cost += g[1] + g[0] + c[2] + c[1];
            //printf("CBG cost: %d\n", cost);
        }
    } else {
        cost += b[0] + b[1];
        if (d == 1) { // C, G, B
            cost += g[0] + g[2] + c[1] + c[2];
            //printf("CGB cost: %d\n", cost);
        } else {      // G, C, B
            cost += g[1] + g[2] + c[0] + c[2];
            //printf("GCB cost: %d\n", cost);
        }
    }
    return cost;
}

int main() {
    while (scanf("%d %d %d %d %d %d %d %d %d", &b[0], &g[0], &c[0], &b[1], &g[1], &c[1], &b[2], &g[2], &c[2]) != EOF) {
        int min = __INT_MAX__;
        int d;
        string order = "";
        if ((d = calculateCost(0, 2, 1)) < min) {
            min = d;
            order = "BCG";
        }  
        if ((d = calculateCost(0, 1, 2)) < min) {
            min = d;
            order = "BGC";
        }  
        if ((d = calculateCost(1, 0, 2)) < min) {
            min = d;
            order = "GBC";
        }  if ((d = calculateCost(1, 2, 0)) < min) {
            min = d;
            order = "CBG";
        }  if ((d = calculateCost(2, 1, 0)) < min) {
            min = d;
            order = "CGB";
        }  if ((d = calculateCost(2, 0, 1)) < min) {
            min = d;
            order = "GCB";
        }
        printf("%s %d\n", order.c_str(), min); 
    }
    return 0;
}
