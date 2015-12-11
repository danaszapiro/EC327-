#include <cmath>
#include <iostream>
using namespace std;

float getMean(int myArray[], int size)
{
    float meanVal;
    float sumVal;
    for (int i=0;i<size;i++)
    {
        sumVal+=myArray[i];
    }
    meanVal= sumVal/size;
    return meanVal;
}
    
float getStdDev(int myArray[], int size)
{
    float meanVal;
    int sumVal;
    float stanDev;
    float stdSum;
    for (int i=0;i<size;i++)
    {
        sumVal+=myArray[i];
    }
    meanVal= sumVal/size;
    for (int i=0;i<size; i++)
    {
        stdSum+=((myArray[i]-meanVal)*(myArray[i]-meanVal));
    }
    stanDev= sqrt(stdSum/size);
    return stanDev;
            
}