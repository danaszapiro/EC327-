#include <iostream>
using namespace std; 
#include "pa2Functions.h"
#include <iomanip>
#include <string>

//define entries
extern const int ENTRIES=10;

//main function question 1

int main()
{
     cout.precision(4);
    
    //inizialize variables and ask user for command
    char input;
    initialize();
    cout<<"Please enter command code: "<<endl;
    cin>>input;
    // while valid input check for different commands. 
    while (checkCode(input))
    {
        // if command is q/Q, quit program
        if (input=='q' || input =='Q')
            return 0;
        else
        { 
            //Otherwise, ask user for respective parameters. 
            //for f/F and b/B, only one parameter. call function with input and print out result. 
            cout<< "Please enter command parameters: "<<endl;
            if (input=='F' || input=='f')
            {
                int val;
                cin>>val;
                int result=factorial(val);
                cout<< std::defaultfloat<<"factorial("<<val<<") = ";
                cout<<setprecision(4)<<fixed<<result<<endl;
            }
            else if (input=='B' || input=='b')
            {
                int val;
                cin>>val;
                int result=fibonacci(val);
                cout<< std::defaultfloat<<fixed<<"fibonacci("<<val<<") = ";
                cout<<setprecision(4)<<fixed<<result<<endl;
            }
            
            //for commands r/R, l/L n/N, 3 parameters (first, last, delta). Call function several times with arguments from first to last in steps of delta and print out each result.  
            else if (input=='R' || input=='r')
            {
                double first, last, delta,result;
                cin>>first;
                cin>>last;
                cin>>delta;
                if(first>last || delta==0)
                {
                    cout<<"No computation needed."<<endl;
                }
                int i=0;
                //keep calling function with arguement first+delta*i while less than last+delta  or calling function more times than ENTRIES. 
                for (double val=first; val<=(last+delta) && i<ENTRIES; ++i, val=first+(delta*i) )
                { 
                    // when last increment is more than last, use last value as arguement. 
                    if(val>=last)
                    {
                        val=last;
                        result=findSqrtValue(val);
                        cout<< std::defaultfloat<<"Square root of "<< val <<" = ";
                        cout<<setprecision(4)<<fixed<<result<<endl;
                        break;
                    }
                    result=findSqrtValue(val);
                    cout<< std::defaultfloat<<"Square root of "<< val;
                    cout<<setprecision(4)<<fixed<<" = "<<result<<endl;
                }
            }

            else if (input=='l' || input=='L')
            {
                double first, last, delta,result;
                cin>>first;
                cin>>last;
                cin>>delta;
                if(first>last || delta==0)
                {
                    cout<<"No computation needed."<<endl;
                }
                int i=0;
                for (double val=first; val<=(last+delta) && i<ENTRIES; i++ )
                {
                    val=first+delta*i;
                    if(val>=last)
                    {
                        val=last;
                        result=naturalLog(val);
                        cout<< std::defaultfloat<<"natural log of "<<val<<" = ";
                        cout<<setprecision(4)<<fixed<<result<<endl;
                        break;
                    }
                    result=naturalLog(val);
                    cout<< std::defaultfloat<<"natural log of "<<val<<" = ";
                    cout<<setprecision(4)<<fixed<<result<<endl;
                }
             }
            else if (input=='n' || input=='N')
            {
                double first, last, delta,result;
                cin>>first;
                cin>>last;
                cin>>delta;
                if(first>last || delta==0)
                {
                    cout<<"No computation needed."<<endl;
                }
                int i = 0;
                for (double val=first; val<=(last+delta) && i<ENTRIES; i++ )
                {
                    val=first+(delta*i);
                    if(val>=last)
                    {
                        val=last;
                        result=findNyanCatValue(val);
                        cout<< std::defaultfloat<<"NyanCat value of " <<val<<" = ";
                        cout<<fixed<<result<<endl;
                        break;
                    }
                    result=findNyanCatValue(val);
                    cout<< std::defaultfloat<<"NyanCat value of " <<val<<" = ";
                    cout<<fixed<<result<<endl;
                }
             }
            else if (input=='o'||input=='O')
            {
                string filename;
                cin>>filename;
                writeDataToFile(filename);

            }
            else if (input=='i'||input=='I')
            {
                string filename;
                cin>>filename;
                readDataFromFile(filename);
            }
            else if (input=='d'||input=='D')
            {
                //for command d/D 2 paramenters (first and last).
                double first, last, result;
                cin>>first;
                cin>>last;
                //check, if first more than last. 
                if(first>last)
                {
                    cout<<"No computation needed."<<endl;
                }
                int i = 0;
                double val=first;
                // call function several times with arguement first incremented by 2 each time, until getting to last value or calling function more times than ENTRIES.  
                for (double val=first; val<last && i<(ENTRIES-1); i++ )
                {
                    int result=findNextOddValue(val);
                    cout<<setprecision(4)<<fixed<<result<<", ";
                    val+=2;
                }
                val+=2;
                
                    if(val>=last)
                    {
                        val=last;
                        int result=findNextOddValue(val);
                        cout<<setprecision(4)<<fixed<<result<<endl;
                    }
                    else if (i==(ENTRIES-1))
                    {
                        int result=findNextOddValue(val);
                        cout<<setprecision(4)<<fixed<<result<<endl;
                    }
                             
                }
            }
    //keep asking for new command.             
            
    cout<<"Please enter command code: "<<endl;
    cin>>input; 
        
    }
return 0;
}
