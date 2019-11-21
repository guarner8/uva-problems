#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int n, l; 
    double w;
    while (scanf("%d %d %lf", &n, &l, &w) != EOF) {
        double position, radius;
        int count = 0, impo = 0;;
        vector <tuple<double, double>> list;
        vector <tuple<double, double>> finalList;
        tuple <double, double> in;

        // Read in input
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &position, &radius);
            if (radius <= w/2) continue;
            double reach = sqrt(pow(radius, 2) - pow(w / 2, 2));
            in = make_tuple(position - reach, position + reach);
            list.push_back(in);
        }

        // Sort input
        sort(list.begin(), list.end());

        // Account for l = 0
        if (l == 0) {
            printf("0\n");
            continue;
        }

        // printf("%d %d %lf\n", n, l, w);
        // for (int i = 0; i < list.size(); i++) {
        //     printf("%lf %lf\n", get<0>(list.at(i)), get<1>(list.at(i)));
        // }

        for (int i = 0; i < list.size(); i++) {
            count++;
            double start = get<0>(list.at(i));
            double end = get<1>(list.at(i));
            
            // Case where sprinklers do not reach beginning
            if (i == 0) {
                if (!(start <= 0)) {
                    printf("-1\n");
                    impo = 1;
                    break;
                }
            }

            int flag = 0;
            double maxR = 0;
            double maxL = 0;

            for (int j = i + 1; j < list.size(); j++) {
                // If starting sprinkler < 0 and there is a sprinkler closer to 0 that might replace it
                // if (get<0>(list.at(j)) <= 1) {
                //     printf("%lf %lf\n", start, get<0>(list.at(j)));
                // }

                // TF
                if (start <= 0 && get<0>(list.at(j)) <= 0) {
                    if (end <= get<1>(list.at(j))) {
                        start = get<0>(list.at(j));
                        end = get<1>(list.at(j));
                        list.erase(list.begin(), list.begin()+j) ;
                        j--;
                        continue;
                    }
                }

                // If sprinkler range is contained by another sprinkler's range
                if (start < get<0>(list.at(j)) && end > get<1>(list.at(j))) {
                    list.erase(list.begin() + j);
                    j--;
                }

                // If next sprinkler reaches beyond range of current sprinkler
                if (end >= get<0>(list.at(j)) && end < get<1>(list.at(j))) {
                    flag = 1;
                    if (get<1>(list.at(j)) > maxR) {
                        maxR = get<1>(list.at(j));
                        maxL = get<0>(list.at(j));
                    }
                    list.erase(list.begin() + j);
                    j--;
                }
                               //if (intersection)
                // find circle that has beginning <= previous end
                // choose circle with rightmost reach.
            }

            // Adds only the chosen circle for the case above
            if (flag == 1) {
                in = make_tuple(maxL, maxR);
                list.emplace(list.begin() + i + 1, in);
            }

            // Check when circle reaches end of lawn
            // Might be buggy here
            if (end >= l) {
                // printf("breakpoint: %lf %lf\n", start, end);
                if (list.size() > (i + 1)) {
                    list.erase(list.begin() + i + 1, list.end());
                }
                break;
            }
        }

        // Checks to see if there is more than one sprinkler. If so check to see if the sprinklers are continous.
        if ( list.size() >= 1 && impo == 0) {
            if (get<1>(list.at(list.size()-1)) < l) {
                printf("-1\n");
                impo = 1;
                continue;
            }

            for (int i = 1; i < list.size(); i++) {
                if (get<1>(list.at(i-1)) < get<0>(list.at(i))) {
                    // printf("%lf %lf\n", get<1>(list.at(i-1)), get<0>(list.at(i)));
                    printf("-1\n");
                    impo = 1;
                    break;
                }
            }
        }

        if (list.size() == 0 && impo == 0) {
            printf("-1\n");
            impo = 1;
        }


        // for (int i = 0; i < list.size(); i++) {
        //     printf("start: %lf; end: %lf\n", get<0>(list.at(i)), get<1>(list.at(i)));
        // }
        if (impo != 1)
            printf("%d\n", count);
    }
    return 0;
}


            // Case where multiple sprinklers are found before beginning
            // if (start < 0 && (i + 1 < list.size() - 1) ) {
            //     if ( get<0>(list.at(i + 1)) <= 0 )  {
            //         continue;
            //     }
            // }
