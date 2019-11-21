#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct myComparator {
    bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
        if (lhs[1] == rhs[1]) {
            return lhs[0] > rhs[0];
        }
        return lhs[1] > rhs[1];
    }
};

int main() {
    int cases, numPatients, numDoctors, timeOfArrival, numOffices, val, time;
    
    int anyLeft;

    // Read in number of test cases
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++) {

        // Read in numPatients, numDoctors
        scanf("%d %d", &numPatients, &numDoctors);

        anyLeft = numPatients;

        // Create queue for each patient
        priority_queue<vector<int>, vector<vector<int>>, myComparator> mypq[numDoctors];
        queue <int>patientVisits[numPatients];

        for (int j = 0; j < numPatients; j++) {
            // Read in time of arrival and number of offices to visit
            scanf("%d %d", &timeOfArrival, &numOffices);
            for (int q = 0; q < numOffices; q++) {
                scanf("%d", &val);
                patientVisits[j].push(val);
            }
            int arrivalTime = timeOfArrival;
            int officeNum = patientVisits[j].front();
            patientVisits[j].pop();
            vector <int>ins = {j, timeOfArrival};
            mypq[officeNum-1].push(ins);
        }

        // Begin to simulate time
        time = 0;
        while (anyLeft > 0) {
            // Add patients to offices
            for (int j = 0; j < numDoctors; j++) {
                if (!mypq[j].empty()) {
                    // if top is at the front of the office
                    if (time >= mypq[j].top().at(1)) {
                        int indexNeeded = mypq[j].top().at(0);
                        mypq[j].pop();
                        if (patientVisits[indexNeeded].empty()) {
                            anyLeft--;
                        } else {
                            int nextVal = patientVisits[indexNeeded].front();
                            patientVisits[indexNeeded].pop();
                            vector<int> nextIns = {indexNeeded, time+1};
                            mypq[nextVal-1].push(nextIns);
                        }
                    }
                }
            }
            
            time++;
        }
        printf("%d\n", time);
    }
    return 0;
}
