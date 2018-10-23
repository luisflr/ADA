#include <iostream>
#include <ctime>
#include <dos.h>
#include <cassert>
using namespace std;
#define N 100000

int array[N];
void inicia()
{
	for(int i = 0; i<N; i++)
	{
		array[i] = (rand()%N) -(N/2);
	}
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  		quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x)   
            return mid; 
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
   } 
   return -1; 
} 

void cont(int arr[])
{
	int cont_ = 0;
	int sum;
	int bs;
	for(int i = 0; i < N-1; i++)
	{
		sum = arr[i] + arr[i+1];
		bs = binarySearch(arr, 0, N-1, (sum * -1));
		if(bs != -1)
		{	
			cont_++;
		}
		
	}
	
	//cout<<cont_;
}

int main()
{
	double t0, t1;
	inicia();
	quickSort(array, 0, N - 1);
	t0  = clock();
	cont(array);
	t1 = clock();
	double time = ((t1-t0)/CLOCKS_PER_SEC);
	cout<< time;
	
	return 0;
}
