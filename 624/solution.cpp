#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int total, n;
int currSum;
vector <int> sol;
vector <int> curr;
int in[20];

void solve(int index, int length, int sum, vector<int> sol) {
    if (sum > currSum && sum <= total) {
        currSum = sum;
        curr = sol;
    }
    if (sum > total) return;
    for (int i = index; i < n; i++) {
        sol.push_back(in[i]);
        solve(i+1, length+1, sum + in[i], sol);
        sol.pop_back();
    }
}

int main() {
    while (scanf("%d %d", &total, &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }

        currSum = 0;
        curr.clear();

        solve(0, 0, 0, sol);
        for (int i = 0; i < curr.size(); i++) {
            printf("%d ", curr[i]);
        }
        printf("sum:%d\n", currSum);
    }
    return 0;
}
