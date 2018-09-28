#include <iostream>
#include "stack.h" 
#define N 7
using namespace std;

int dolares(int precios[],int m,int M)
{
	stack<int> s1;
	stack<int> s2;
	int ganancia,g1,g2;
	int mtemp=m,Mtemp=M;
    while(m< N-1 && M>0)
    {
    	
    	if(m==N-2 || M==1)
    	{
    		if(precios[m]<precios[mtemp]){
    			ganancia=max(ganancia,precios[N-1]-precios[m]);
    			cout<<ganancia;
    			return ganancia;
			}
			else if(precios[M]>precios[Mtemp]){
				ganancia=max(ganancia,precios[M]-precios[0]);
				cout<<ganancia;
				return ganancia;
			}
		} 
    	if(precios[m]<precios[mtemp] || precios[m]==precios[mtemp]) 
		{
			mtemp=m;
			s1.push(precios[m]);	
		} 
		m=m+1;	
		if(precios[M]>precios[Mtemp] || precios[M]==precios[Mtemp])
		{
			Mtemp=M;
			s2.push(precios[M]);
		}
		M=M-1;
		if((m>M) && (precios[M]>precios[Mtemp]) && (precios[m]<precios[mtemp]))
    	{
    		ganancia=max(precios[M]-precios[mtemp],(precios[M]-precios[m])-100);
		}
		g1=s1.top();
		g2=s2.top();
    	ganancia=g2-g1;	
	}
	cout<<ganancia;
	return ganancia;
}

int main()
{
	//int precios[N] = {35,15,49,28,10,40};
	//int precios[N] = {49,35,15,28,10,40};
	//int precios[N] = {40,10,35,49,28,15};
	int precios[N] = {0,60,2,20,1,40,10};
	//int precios[N] = {1,1,1,1,1,1,1};
	dolares(precios,0,N-1);
	return 0;
}
