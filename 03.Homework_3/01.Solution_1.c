#include<stdio.h>
#include<math.h>


int triangle(double side_a, double side_b, double side_c, double *P, double *S){
    
    double half_P = 0;
    // Check if the values of the sides of the triangle are positive numbers
    if(side_a <= 0 || side_b <= 0 || side_c <= 0){

        return -1;
    }
    // Check whether the sum of any two sides is greater than the third side
    if(((side_a + side_b) <= side_c) 
       || ((side_a + side_c) <= side_b) 
       || ((side_b + side_c) <= side_a)){

        return -1;
    }
    // Write the value of the perimeter variable, using the P pointer
    *P = side_a + side_b + side_c;
    half_P = (side_a + side_b + side_c) / 2;
    // Write the value of the area variable, using the S pointer
    *S = sqrt(half_P * ((half_P - side_a) * (half_P - side_b) * (half_P - side_c)));
    
    return 0;
}

int main() {

    double perimeter, area;
    double a, b, c;

    while (scanf("%lf %lf %lf", &a, &b, &c)!=EOF)


    if (triangle(a, b, c, &perimeter, &area) == 0){
        printf("\nP = %.3f, S = %.3f\n", perimeter, area);
    }else {
        printf("\nInvalid triangle sides!\n");
    }


    return 0;
}