#include <string.h>
#include <cstdio>
#include <queue>

using namespace std;

/* Team Queue */
int main() {
    int teams, players, pNum, belongsTo, next, counter = 1;
    char instruction[10];
    // Import the players and to which team they belong
    scanf("%d", &teams);
    while (teams != 0) {
        
        int belongingTeam[1000005];
        queue <int>teamQueue[10005];
        queue <int>orderQueue;
        
        // Iterate through teams and label players
        for (int j = 0; j < teams; j++) {
            // Get # of players per team
            scanf("%d", &players);
            // Set which team they belong to
            for (int i = 0; i < players; i++) {
                scanf("%d", &pNum);
                belongingTeam[pNum] = j;
            }
        }

        printf("Scenario #%d\n", counter);
        // Iterate through the instructions
        scanf("%s", instruction);
        while (strcmp(instruction, "STOP")) {
            
            // Enqueue
            if (strcmp(instruction, "ENQUEUE") == 0) {
                scanf("%d", &next);
                int belongsTo = belongingTeam[next];

                if (teamQueue[belongsTo].empty()) {
                    orderQueue.push(belongsTo);
                }
                teamQueue[belongsTo].push(next);
            } 
            // Dequeue
            else {
                if (!orderQueue.empty()) {
                    int first = orderQueue.front();
                    int out = teamQueue[first].front();
                    printf("%d\n", out);
                    teamQueue[first].pop();
                    if (teamQueue[first].empty())
                        orderQueue.pop();
                }
            }

            // Get next instruction
            scanf("%s", instruction);
        }
        printf("\n");
        counter++;
        // Get next set of teams;
        scanf("%d", &teams);
    }
    
    return 0;
}
