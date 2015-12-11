#include <iostream>
using namespace std; 

int * ReverseMultiply (int *list, int size);

int main()
{
    //ask user for number of entries
    int size;
    cout<<"Enter the number of entries: "<<endl;
    cin>>size;
    
    //keep asking for entries until array is complete.
    int* list= new int[2*size+1];
    for(int i=0; i<size;i++)
    {
        int entrie;
        cout<<"Entry "<<i<<" is: "<<endl;
        cin>>list[i];
    }
    cout<<"*****"<<endl;
    
    //call reverse multiply function
    list=ReverseMultiply (list, size);
    cout<<"Original array is: ";
    //print out original array
    for (int i=0;i<size;i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<"and the address of the zero element is: "<<list<<endl;
    
    //printout final array
    cout<<"Final array is: ";
    for (int i=0;i<=size*2;i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<" and the address of zero element is: "<<list<<endl;
    return 0 ;
}

//reverse multiply function
int * ReverseMultiply (int *list, int size)
{
    //create new array of integers on the heap
    int newSize=size*2+1;
    int* newList= new int[newSize];
    int product=1;
    //copy first values in original array to new array
    for(int i=0;i<size;i++)
    {
        newList[i]=list[i];
    }
    // add revesed original array to new array
    for(int i=size, j=size-1;i<newSize;i++, j--)
    {
        newList[i]=list[j];
    }
    //compute product of all values in newarray
    for (int i=0;i<newSize-1;i++)
    {
        int val=*(newList+i);
        product=product*val;
    }
    newList[newSize-1]=product;
    return newList;
}