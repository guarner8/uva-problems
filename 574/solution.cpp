#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int total, n;
vector <int> sol;
map <vector <int>, bool> solution;
int in[20];

void solve(int index, int length, int sum, vector<int> sol) {
    if (sum == total) {
        if (solution[sol] == true) return;
        solution[sol] = true;
        for (int i = 0; i < length; i++) {
            if (i != length-1) {
                printf("%d+", sol[i]);
            } else {
                printf("%d", sol[i]);
            }
        }
        printf("\n");
        return;
    }
    if (sum > total) return;
    for (int i = index; i < n; i++) {
        sol.push_back(in[i]);
        solve(i+1, length+1, sum + in[i], sol);
        sol.pop_back();
    }
}

int main() {
    scanf("%d %d", &total, &n);
    while (total != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        solution.clear();
        printf("Sums of %d:\n", total);
        solve(0, 0, 0, sol);
        if (solution.size() == 0) printf("NONE\n");
        scanf("%d %d", &total, &n);
    }
    return 0;
}
