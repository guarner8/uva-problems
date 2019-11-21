#include <cstdio>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, top, flag = 0;
    bool did = false;
    scanf("%d", &n);
    while (n != 0) {
        if (flag != 0) {
            printf("\n");
        }

        did = false;
        for (int i = 1234; i <= 98765 / n; i++) {
            top = i * n;
            // check if all ten digits are used, if they are then print
            set <int, greater <int>> check;
            check.clear(); 

            string stringTop = to_string(top);
            string stringBottom = "";
            if (top < 9999) {
                stringTop = '0' + to_string(top);
            } else {
                stringBottom = to_string(i);
            }

            if (i < 9999) {
                stringBottom = '0' + to_string(i);
            } else {
                stringBottom = to_string(i);
            }

            for (int j = 0; j < 5; j++) {
                int digitTop = stringTop[j] - '0';
                int digitBottom = stringBottom[j] - '0';
                check.insert( digitTop);
                check.insert( digitBottom);
            }
            if (check.size() == 10) {
//  for (std::set<int>::iterator it=check.begin(); it!=check.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

                printf("%d / %s = %d\n", top, stringBottom.c_str(), n);
                flag = 1;
                did = true;
            }
        }   
        if (did != true) {
            printf("There are no solutions for %d.\n", n);
            flag = 1;
        }

        scanf("%d", &n);
    }
    return 0;
}
