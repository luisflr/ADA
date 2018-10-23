#include <iostream>
#include <ctime>
#include <dos.h>
#include <cassert>
using namespace std;
#define N 100000

int array[N];
int cont = 0;
void inicia()
{
	for(int i = 0; i<N; i++)
	{
		array[i] = (rand()%N) -(N/2);
	}
}

void suma_dos(int array[])
{
	for (int i = 0; i<N; i++)
	{
		for(int j = i+1; j<N; j++)
		{
			if(array[i] + array[j] == 0)
			{
				cont++; 
			}
		}
	}
	
}

void suma_tres(int array[])

{
	for (int i = 0; i<N; i++)
	{
		for(int j = i+1; j<N; j++)
		{
			for(int k = j+1; k<N; k++)
			if(array[i] + array[j] + array[k] == 0)
			{
				cont++; 
			}
		}
	}
	
}

int main()
{
	double t0, t1;
	inicia();
	t0 = clock();
	suma_tres(array);
	t1 = clock();
	
	double time = ((t1-t0)/CLOCKS_PER_SEC);
	cout<< time;
	return 0;
}
