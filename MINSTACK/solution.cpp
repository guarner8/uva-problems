#include <cstdio>
#include <string>
#include <stack>
#include <string.h>

using namespace std;

int main() {
    int loop, nextNum, check;
    char nextIns[10];

    stack <int> values;
    stack <int> mins;

    scanf("%d", &loop);

    for (int i = 0; i < loop; i++) {
        scanf("%s %d", nextIns, &nextNum);
        if (strcmp(nextIns,"PUSH") == 0) {

            // Check first value if smaller then push
            if (!mins.empty()) {
                if (mins.top() >= nextNum) {
                    mins.push(nextNum);
                }
            } else {
                mins.push(nextNum);
            }

            // Push onto stack
            values.push(nextNum);

        } else {
            if (strcmp(nextIns, "MIN") == 0) {
                if (!mins.empty()) {
                    printf("%d\n", mins.top());
                } else {
                    printf("EMPTY\n");
                }
            } else {
                if (!values.empty()) {
                    check = values.top(); 
                    if (!mins.empty()) {
                        if (check == mins.top()) {
                            mins.pop();
                        }
                    }
                    values.pop();
                } else {
                    printf("EMPTY\n");
                }
            }
        }
    }

}
