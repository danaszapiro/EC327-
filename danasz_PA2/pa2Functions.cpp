#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

extern const int ENTRIES;
//initialize function, prints out required information and ENTRIES value. 
void initialize()
{
    cout<<"EC327: Introduction to Software Engineering "<<endl;
    cout<<"Fall 2015"<<endl;
    cout<<"Programming Assignment 2"<<endl;
    cout<<"Value of Entries is: "<<ENTRIES<<endl;
}

//check code function, check for valid command. 
bool checkCode(char input)
{
    if (input == 'f' || input == 'F' || input == 'b' || input == 'B' || input == 'r' || input == 'R' || input == 'D' || input == 'd' || input == 'L' || input == 'l' || input == 'N' || input == 'n' || input == 'I' || input == 'i' || input == 'o' || input == 'O' || input == 'q' || input == 'Q')
        return true;
    else
        cout<<"Invalid command code"<<endl;
        return false;
}

void writeDataToFile(string filename)
{
    fstream inout; 
    inout.open(filename, ios::out );
}
void readDataFromFile(string filename)
{
    string data;
    fstream inout;
    inout.open(filename, ios::in) ;
    while(!inout.eof())
    {
        inout>>data;
        cout<<data;
        if(ios:: eofbit)
        {
            cout<<endl;
        }
    }
  inout.close();  
}

double findNyanCatValue(double input)
{
    double result=(2 * input) + (input * pow(6,input));
    return result;
}

//factorial function, uses recursive call to calculate factorial value. returns corresponding integer. 
int factorial(int input)
{
    if (input==0)
        return 1;
    else 
        return input*factorial(input-1);
}

//fibonacci function. returns integer value at index of arguement with which the function was called. 

int fibonacci(int input)
{
    if (input == 0)
        return 0;
    else if (input == 1)
        return 1;
    else
    {
        //if arguement more than 1, calculate fibbonacci values until reaching index.  
        int result;
        int temp1=0;
        int temp2=1;
        for(int i=1;i<input;i++)
        {
            result=temp1+temp2;
            temp1=temp2;
            temp2=result;
        }
        return result;
    }
    
}

//find square root value function. Returns double value for the squareroot of arguement. (using cmath)
double findSqrtValue(double input)
{
    double result=sqrt(input);
    return result;
}
//natural log function. Returns double value of natural log of arguement. (using cmath)
double naturalLog(double input)
{
    double result=log(input);
    return result;
}

//next odd function. returns closest and higher odd integer value for arguement. 

int findNextOddValue(int input)
{
    int result;
    //if arguement is odd, return arguement
    if (input%2==1)
        result=input;
    //if arguement is even, return arguement +1
    if (input%2==0)
        result = input+1;
    return result;
}