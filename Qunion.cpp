#include<iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <cassert>
#define N 20
using namespace std;


struct quickunion_compresion
{
    int id[N];
    int size[N];
    ofstream ficheros;
    void init()
    {
        for(int i=0;i<N;i++)
        {
            id[i] = i;
            size[i] = 1;
        }
    }
    
    int root(int n)
    {
        int temp = id[n];
        while(id[temp] != temp)
        {
            id[temp] = id[id[temp]]; //compresion de camino
            temp = id[temp];
            
        }
        return temp;
    }
    bool conectado(int p, int q)
    {
        return (root(p) == root(q));
    }
    void join(int p, int q)
    {
        int root_p = root(p);
        int root_q = root(q);
        if(conectado(p,q))
            return;
            
        if(size[root_p] <= size[root_q])
        {
            id[root(p)] = root(q);
            size[root_q] += size[root_q];
        }
        
        else
        {
            id[root_q] = root_p;
            size[root_p] += size[root_q];
        }
    }
    
    void print()
    {
    	ficheros.open("g1.txt");
    	ficheros<<"graph {"<<endl;
        for(int i=0;i<N;i++)
        {
        	if(id[i] == i)
        	{
        		for (int j=0;j<N;j++)
        		{
        			if (conectado(i,j))
					{
						ficheros<<i<< " -- " <<j<<";"<<endl;
					}	
				}
        		
			}
            //cout << id[i] << "-";
        }
        ficheros<<"}"<<endl;
        ficheros.close();
    }
};

struct quick_union
{
    int id[N];
    ofstream ficheros1;
    void init()
    {
        for(int i=0;i<N;i++)
        {
            id[i] = i;
        }
    }
    
    int root(int n)
    {
        int temp = id[n];
        while(id[temp] != temp)
        {
            temp = id[temp];
        }
        
        return temp;
    }
    bool conectado(int p, int q)
    {
        return (root(p) == root(q));
    }
    void join(int p, int q)
    {
        
        id[root(p)] = root(q);   
    }
    
    void print()
    {
    	for(int i=0;i<N;i++)
        {
            cout << id[i] << "-";
        }
    }
    void print1()
    {
    	ficheros1.open("g2.txt");
    	ficheros1<<"graph {"<<endl;
        for(int i=0;i<N;i++)
        {
        	if(id[i] == i)
        	{
        		for (int j=0;j<N;j++)
        		{
        			if (conectado(i,j))
					{
						ficheros1<<i<< " -- " <<j<<";"<<endl;
					}	
				}
        		
			}
            //cout << id[i] << "-";
        }
        ficheros1<<"}"<<endl;
        ficheros1.close();
	}
};


int main()
{
    quickunion_compresion prueba;
    quick_union prueba1;
    prueba1.init();
    prueba.init();
//	clock_t comienzo;
//  comienzo = clock();
    for(int i=0;i<N;i++)
    {
    	int p=rand()%N;
    	int q=rand()%N;
    	prueba.join(p,q);
	}
	for(int j=0;j<N;j++)
    {
    	int r=rand()%N;
    	int s=rand()%N;
    	prueba1.join(r,s);
	}
	prueba.print();
	prueba1.print1();
    return 0;
}



