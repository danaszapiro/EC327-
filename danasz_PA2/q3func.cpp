#include <fstream>
#include <ctime>
using namespace std;
    
int DataToFile(const char *filename, int N, int M)
{
	int num;
    srand(time(NULL));
	ofstream output;
    M++;
	output.open(filename);
	for (int i=0; i<N ;i++)
	{
		num=rand()% M;
		output<<num<<endl;
    
        if (i==N-1)
        {
            output.close();
            return 0;
        }
       
    }
		return 1;
}

int DataFromFile(const char *filename, int myArray[], int &size)
{
    ifstream input(filename);
    size=0;
    int i=0;
    if(input.fail())    
        return 1;
    while(!input.eof())
    {
        input>>myArray[i];
        size++;
        i++;
        
        if (input.eof())
        {
            size--;
            input.close();
            return 0;
        }
    }
    return 0;
}
