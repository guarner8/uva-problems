#include <cstdio>
#include <string>

int main() {
    int requirements, proposals, metRequirements, d, i, j;
    double value, maxCompliance, maxValue;
    std::string result, finalresult;
    char next[80], nameOfProposal[80];

    scanf("%d %d", &requirements, &proposals);
    while (requirements != 0 && proposals != 0) {
        getchar();
        d++;
        maxCompliance = 0;
        maxValue = 10000000000000;
        for (i = 0; i < requirements; i++) {
                // skip the requirements
                scanf("%[^\n]s", next);
                getchar();
        }

        for (i = 0; i < proposals; i++) {
            // name of car
            scanf("%[^\n]s", nameOfProposal); 
            getchar();
            // value and met requirments
            scanf("%lf %d", &value, &metRequirements);
            getchar();

            if (((double) metRequirements / (double) requirements) >= maxCompliance) {
                if (((double) metRequirements / (double) requirements) == maxCompliance) {
                    if (value <  maxValue) {
                        result = "RFP #";
                        result += std::to_string(d);
                        result += "\n";
                        result += nameOfProposal;
                        result += "\n\n";
                        maxValue = value;
                        maxCompliance = (double) metRequirements / (double) requirements;
                    }
                } else {
                        result = "RFP #";
                        result += std::to_string(d);
                        result += "\n";
                        result += nameOfProposal;
                        result += "\n\n";
                        maxValue = value;
                        maxCompliance = (double) metRequirements / (double) requirements;

                }
            }
            // skip over requirements
            for (j = 0; j < metRequirements; j++) {
                scanf("%[^\n]s", next);
                getchar();
            }
        }

        finalresult.append(result);

        scanf("%d %d", &requirements, &proposals);
    }
    finalresult.erase(finalresult.length() -1);
    printf("%s", finalresult.c_str());
    return 0;
}
