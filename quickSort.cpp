#include <iostream>
#define N 8
using namespace std;

void swap(int a[],int x,int y)
{
	int temp;
	temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}

int partition(int a[],int p,int r)
{
	int x=a[r];
	int i=p-1;
	int temp;
	int temp2;
	for(int j =p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}	
	}
	temp2=a[i+1];
	a[i+1]=a[r];
	a[r]=temp2;
	return i+1;
}

void quickSort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}	
}

void print(int a[])
{
	for (int i=0;i<N;i++)
	{
		cout<<a[i]<<"-";
	}
}

int main()
{
	int a[N]={2,8,7,4,3,5,6,1};
	int p=0;
	int r=N-1;
	quickSort(a,p,r);
	print(a);
}
