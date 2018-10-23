#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <dos.h>

using namespace std;
#define T 100
#define N (T * T) + 2
class union_find
{
	private:
		
	    int id[N];
	    int size[N];
	    int state[N]; 
    
    public:
    	
	    void init()
	    {
	    	
	        for(int i = 0;i < N ;i++)
	        {
	            id[i] = i;
	            size[i] = 1;
	            state[i] = 0;
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
	            size[root_q] += size[root_p];
	        }
	        
	        else
	        {
	            id[root_q] = root_p;
	            size[root_p] += size[root_q];
	        }
	    }
	    
	    void print()
	    {
	        for(int i=1;i < N - 1;i++)
	        {
	            cout << state[i] << " ";
	            if(i % T == 0)
	            {
	            	cout<< endl;
				}
	        }
	    }
	    
	    int cont_b()
	    {
	    	int cont = 0;
	    	for(int i = 1; i<N-1; i++)
	    	{
	    		if(state[i] == 1)
	    		{
	    			cont++;
				}
			}
			
			return cont;
		}	    
		
	    float prob_filtracion()
	    {
	    	int temp = N - 2;
	    	float p;
	    	int t = 0;
	    	int random;
	    	for(;;)
	    	{
	    		if(conectado(0, N - 1) == 1)
				{
					break;
				}
				random = 1+rand()%((temp - 1));
	    		state[random] = 1;
	    		
	    		for(int i = 1; i <= T; i++)
	    		{
	    			if(state[i] == 1)
	    			{
	    				join(i,0);
					}
					if(state[N-i-1] == 1)
					{
						join((N-i-1), (N-1));
					}
				}
				
				for(int i = T+1; i<(N-2); i++)

				{
					if( state[i] == 1 && state[i - T] == 1)
					{
						join(i, (i-T));
					}
					
				}				
				
				
				p = (cont_b() * 100)/(N-2);
				
			}
	    	return p;
		}
};

int main()
{
	double t0, t1;
    union_find prueba;
    prueba.init();

	cout<< prueba.prob_filtracion()/100<<endl;
	//prueba.print();

    return 0;
}
