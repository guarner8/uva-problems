#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int testCases;
    int numJobs;
    int jobPos;
    int next;
    int time;
    bool sw;
    int priority [10];
    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++) {
        queue <int> jobs;
        for (int j = 0; j < 9; j++) {
            priority[j] = 0;
        }

        scanf("%d %d", &numJobs, &jobPos);
        for (int j = 0; j < numJobs; j++) {
            scanf("%d", &next);
            priority[next-1] += 1;
            jobs.push(next);
        }
        time = 0;
        while (jobPos >= 0) {
            sw = 0;
            next = jobs.front();
            jobs.pop();
            for (int q = 8; q > 0; q--) {
                if (q < next)
                    break;
                if (priority[q] > 0 && (q+1) > next) {
                    sw = 1;
                    jobs.push(next);
                    if (jobPos == 0) {
                        jobPos = jobs.size()-1;
                    } else {
                        jobPos--;
                    }
                    break;
                } 
            }
            if (sw == 1)
                continue;

            priority[next-1] -= 1;
            time++;
            jobPos--;
        }
        printf("%d\n", time);
    }
}
