#define _USE_MATH_DEFINES
#include <stdio.h> 
#include <math.h>


float sphereVolume (float radius)
{
    float volume;
    float pi = 3.14159;
    volume =  (4 / 3) * pi * (radius * radius * radius);
    return volume;
}
int main()
{
    float radius;
    float volume;
    printf("Enter radius of sphere");
    scanf("%f",&radius);

    return(0);
}