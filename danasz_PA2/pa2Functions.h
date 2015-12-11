#ifndef PA2FUNCTIONS_H
#define PA2FUNCTIONS_H

extern const int ENTRIES;
//function header

void initialize();
bool checkCode(char);
void writeDataToFile(string);
void readDataFromFile(string);
double findNyanCatValue(double);
int factorial(int);
int fibonacci(int);
double findSqrtValue(double);
double naturalLog(double);
int findNextOddValue(int);

#endif