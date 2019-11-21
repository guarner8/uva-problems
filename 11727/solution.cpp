#include <cstdio>
#include <string>

int main() {
    int loop, s1, s2, s3, i;
    std::string result;
    scanf("%d", &loop);

    for (i = 0; i < loop; i++) {
        result.append("Case ");
        result += std::to_string(i+1);
        result.append(": ");
        scanf("%d %d %d", &s1, &s2, &s3);
        if ((s1 > s2 && s1 < s3) || (s1 < s2 && s1 > s3)) {
            result += std::to_string(s1);
        } else if ((s2 > s1 && s2 < s3) || (s2 < s1 && s2 > s3)) {
            result += std::to_string(s2);
        } else {
            result += std::to_string(s3);
        }
        result.append("\n");
    }

    printf("%s", result.c_str());

    return 0;
}
