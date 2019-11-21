#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    long days, max, min, sales, value, paid;
    scanf("%ld", &days);
    while (days != 0) {
        std::vector<long> tickets;
        paid = 0;
        for (int i = 0; i < days; i++) {
            scanf("%ld", &sales);
            for (int j = 0; j < sales; j++) {
                scanf("%ld", &value);
                tickets.insert(tickets.end(), value);
            }
            if (sales > 0) {
                sort(tickets.begin(), tickets.end());
            }
            
            max = tickets.back();
            min = tickets.front();
            
            paid += max-min;

            tickets.erase(tickets.begin());
            tickets.pop_back();
        }


        printf("%ld\n", paid);
        scanf("%ld", &days);
    }
    return 0;
}
