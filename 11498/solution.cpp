#include <cstdio>
#include <string>

int main() {
    int loop, xorigin, yorigin, xpos, ypos, i;
    scanf("%d", &loop);
    while (loop != 0) {
        scanf("%d %d", &xorigin, &yorigin);
        std::string result;
        for (i = 0; i < loop; i++) {
            scanf("%d %d", &xpos, &ypos);
            if (xpos == xorigin || ypos == yorigin) {
                result.append("divisa\n");
                continue;
            }

            if (ypos > yorigin)
                result.append("N");
            else
                result.append("S");
            if (xpos < xorigin) 
                result.append("O\n");
            else
                result.append("E\n");
        }
        printf("%s", result.c_str());
        scanf("%d", &loop);
    }
    return 0;
}
