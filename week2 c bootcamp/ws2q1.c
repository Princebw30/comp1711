#include <stdio.h>
#include <math.h>


float circleArea(float radius)
{
    float area;
    float pi = 3.14159;
    area = radius * radius * pi;
    return (area);
}
int main()
{
    float radius;
    float area;
    printf("Type in radius of circle");
    scanf( "%f", &radius);
    area = circleArea(radius);
    printf("Area of circle with radius of %f is %f\n" , radius , area);

    return(0);
}