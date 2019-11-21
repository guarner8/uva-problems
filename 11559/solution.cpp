#include <cstdio>
#include <string>

int main() {
    int i, j, numParticipants, budget, numHotels, numWeeks, price, numBeds, minPrice, maxBeds;
    std::string result;

    while (scanf("%d %d %d %d", &numParticipants, &budget, &numHotels, &numWeeks) != EOF) {
        minPrice = budget + 1;

        for (i = 0; i < numHotels; i++) {
            scanf("%d", &price);
            maxBeds = 0;
            // check if there are enough beds in the hotel
            for (j = 0; j < numWeeks; j++) {
                scanf("%d", &numBeds);
                if (numBeds > maxBeds)
                    maxBeds = numBeds;
            }
            // if there are enough beds
            // if the price is cheaper than cheapest
            if (maxBeds >= numParticipants)
                if (minPrice > (price*numParticipants))
                    minPrice = price * numParticipants;
        }


        if (minPrice > budget)
            result = "stay home\n";
        else { 
            result = std::to_string(minPrice);
            result.append("\n");
        }

        printf("%s", result.c_str());

    }

    return 0;
}
