#include <cstdio>
#include <math.h> 

#define PI 3.14159265

using namespace std; 

int main() {
    double L, n, C;
    scanf("%lf %lf %lf", &L, &n, &C);
    while (L != -1) {
        double LStar = (1 + n * C) * L;
        double l = PI;
        double r = 0;
        double theta;

        int count = 0;

        if (L == LStar) {
            printf("0.000\n");
            scanf("%lf %lf %lf", &L, &n, &C);
            continue;
        };


        /// We play with r
        // double radius;
        // double theta1;
        // double theta2;
        // double ratio = 200;

        // for (int i = 0; i < 50; i++) {
        //     radius = (l + r) / 2;
        //     theta1 = LStar / radius;
        //     theta2 = 2 * asin( L / (2 * radius));
        //     ratio = theta1 / theta2;
        //     if (ratio < 1) {
        //         r = radius;
        //     } else {
        //         l = radius;
        //     }
        //     printf("ratio: %lf\n", ratio);
        // }

        // double r1; //= L / (2 * sin(theta / 2));
        // double r2;// = LStar / theta;
        // for (int i = 1; i < 100; i++) {
        //     theta = (l + r) / 2;
        //     r1 = L / (2 * sin(theta / 2));
        //     r2 = LStar / theta;
        //     printf("%.32lf\n", r1 - r2);
        //     if ((r1 / r2) < 1) {
        //         r = theta;
        //     } else {
        //         l = theta;
        //     }
        // }
       
        // double a = 1;
        // double b = 2 * radius;
        // double c = ((L*L) / 4);

        // double d = -(-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        // printf("%lf\n", d);
        // scanf("%lf %lf %lf", &L, &n, &C);

        double ratio = LStar / L;
        double varRatio = theta / (2 * sin(theta / 2));
        while (count <  100) {
            count++;
            theta = (l + r) / 2;
            varRatio = theta / (2 * sin(theta / 2));
            // printf("L' / L = %lf\n", (LStar / L));
            // printf("theta / (2sin(theta/2)) = %lf\n", ratio - varRatio);
            if (varRatio > ratio) {
                l = theta;
            } else {
                r = theta;
            }
        }

        double a = 1;
        double b = -2*(LStar / theta);
        double c = pow((L / 2), 2);

        double d = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("%.3lf\n", d);
        scanf("%lf %lf %lf", &L, &n, &C);
    }
    return 0;
}


// int main ()
// {
//   double param, result;
//   param = 0.5;
//   result = asin (param) * 180.0 / PI;
//   printf ("The arc sine of %f is %f degrees\n", param, result);
//   return 0;
// }
