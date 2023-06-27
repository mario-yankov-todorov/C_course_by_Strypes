#include <math.h>
#include <stdio.h>

int quadEq(double a, double b, double c, double* x1, double* x2){

    double discriminant, realPart, imagPart;

    discriminant = (b * b) - (4 * a * c);

    // Check if x1 and x2 are real and different
    if (discriminant > 0) {
        *x1 = (-b - sqrt(discriminant)) / (2 * a);
        *x2 = (-b + sqrt(discriminant)) / (2 * a);
        return 0;
    }

    // Check if x1 and x2 are real and equal
    else if (discriminant == 0) {
        *x1 = *x2 = -b / (2 * a);
        return 0;
    }

    // If roots are not real
    else {
        return -1;
    }

}

int main() {

    double x1, x2;
    double a, b, c;

    printf("Please, enter coefficients a, b and c: ");

    scanf("%lf %lf %lf", &a, &b, &c);

    if (quadEq(a, b, c, &x1, &x2) == 0){
        printf("\nx1 = %.3f, x2 = %.3f\n", x1, x2);
    }else {
        printf("\nNo real roots!\n");
    }


    return 0;
}