#include <cstdio>
#include <string>

int main() {
    double value, loanPayed, downPayment, loanWorth, monthlyPayment, rate;
    int timesDepreciated, duration, i, totalMonths, j;
    std::string result;

    scanf("%d %lf %lf %d", &duration, &downPayment, &loanWorth, &timesDepreciated);
    while (duration >= 0) {

        // Set car value
        value = loanWorth + downPayment;
        monthlyPayment = loanWorth / duration;

        // Get depreciation rates
        int numMonth [timesDepreciated];
        double rates [timesDepreciated];
        for (i = 0; i < timesDepreciated; i++) {
            scanf("%d %lf", &numMonth[i], &rates[i]);
        }

        // Depreciate month 0
        rate = rates[0];
        value = value * (1-rate);
        if (value > loanWorth) {
            result.append("0 months\n");
            scanf("%d %lf %lf %d", &duration, &downPayment, &loanWorth, &timesDepreciated);
            continue;
        }

        // Depreciate and check if value is over under 
        for (i = 1, j = 1; i < duration+1; i++) {
            if (i == numMonth[j]) {
                rate = rates[j];
                j++;
            }

            loanWorth -= monthlyPayment;
            value = value * (1-rate);
            if (value > loanWorth) {
                if (i == 1) {
                    result.append("1 month\n");
                } else {
                    result += std::to_string(i);
                    result.append(" months\n");
                }
                break;
            }
        }

        // Next input
        scanf("%d %lf %lf %d", &duration, &downPayment, &loanWorth, &timesDepreciated);
    }

    printf("%s", result.c_str());
    return 0;
}
