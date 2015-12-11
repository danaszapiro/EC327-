++#include<iostream>
using namespace std;
int m = 0;

void PrintRhombus(int n);

int main()
{
    int num;
    cout<<"Enter a number [1-9]: "<<endl;
    cin>>num;
    m = num;
    if (num >0 && num<=9)
    {
        PrintRhombus(num);
        cout<<endl;
    }
    
    else
        cout<<"Wrong input, please enter a single digit number between 1 and 9."<<endl;
    return 0;
}

void PrintRhombus(int input)
{   
    if (input<=0)
    {
        if((m+input)==0)
        {
            return;
        }
        int space=((-1)*input)+1;
        for(int j= space; j>=0; j--)
            cout<<"  ";

        for (int i=1 ; i<(m+input-1) ; i++)
        {       
            cout<<i<<" ";
        }
        for(int k=((m+input)-1); k>=1;k--)
        {
            cout<<k<<" ";
            if (k==1)
            {
                cout<<endl;
                break;
            }
        }

    }
    if(input > 0)
    {
        int space=input;
        for(int j=space; j>0; j--)
                cout<<"  ";

        for (int i=1 ; i<(m-input+1) ; i++)
        {    
            cout<<i<<" ";
        }
        for(int k=(m-input+1); k>=1;k--)
        {
            cout<<k<<" ";
                if (k==1)
                {
                    cout<<endl;
                    break;
                }
        }
    }
    input--;
    PrintRhombus(input);


}

