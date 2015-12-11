#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "q3func.h"
#include "statistics.h"

int main()
{ // commented out call of DataTofile used to check the program.
    int check;
    //int N=5;
    //int M=50;
    //int size=0;
    int myArray[1000];
    float meanval, stanDev;
    const char* filename = "numbers.txt";
    
    //int a = DataToFile(filename, N, M);
    
    //check if reading from text file was succesfull.

    check=DataFromFile( filename, myArray, size);
    
    // if unsuccesfull of, empty file, print out corresponding message. 
    if (check==1 || size==0)
        {
            cout<<"Array size is: 0"<<endl;
            cout<<"Mean is: None"<<endl;
            cout<<"StdDev is: None"<<endl;
            cout<<"Array values forward are: None" << endl;
            cout<<"Array values reverse are: None" << endl;
            return 0;
        }

    //if reading is succesfull. 
    if (check==0)
    {
        //initialize and declare variables and arrays.
        meanval=getMean( myArray, size);
        stanDev=getStdDev(myArray, size);
        int min = myArray[0];
        int max= myArray[0];

        for(int i = 1 ; i<size; i++)
        {
            if (myArray[i]< min)
            {
                min= myArray[i];
            }
            else if (myArray[i]>max)
            {
                max= myArray[i];
            }
        }
        cout<<"Array size is: "<<(size)<<endl;
        cout<<"Mean is: "<<meanval<<endl;
        cout<<"StdDev is: "<<stanDev<<endl;
        cout<<"Array values forward are: ";
        for (int i=0; i<size-1 ; i++)
        {
           cout<<myArray[i]<<", "; 
        }    
        cout<<myArray[size-1]<<endl;
        cout<<"Array values reverse are: ";
        for (int i=size-1; i>0 ; i--)
        {
           cout<<myArray[i]<<", "; 
        }    
        cout<<myArray[0]<<endl;
        cout<<"The largest array value is: "<<max<<endl;
        cout<<"The smallest array value is: "<<min<<endl;
        return 0;
        
    }
}