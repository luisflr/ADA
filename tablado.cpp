#include <iostream>
#define N 5
#define M 5
#define INF 100
using namespace std;

struct matriz
{
    int A[N][M];
    int i,j;
    
    
    void inicia()
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                A[i][j] = INF;
            }
        }
    }
    
    void print()
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cout << A[i][j] << "-";
            }
            cout << endl;
        }
    }
    
    void ingresar()
    {
        A[0][0] = 1;
        A[0][1] = 2;
        A[0][2] = 4;
        A[0][3] = 7;
        A[0][4] = 8;
        A[1][0] = 3;
        A[1][1] = 5;
        A[1][2] = 9;
        A[2][0] = 10;
        
    }

    void minHeapify(int i, int j)
    {
        int l = i+1; 
        int r = j+1;
        if(l< N && r < M)
        {
            if(A[i][r] == INF && A[l][j]==INF) return;
            if(A[i][r] < A[l][j])
            {
                if(A[i][j] > A[i][r] ){
                swap(A[i][r], A[i][j]);
                //print();
                cout << "-----------------------------" << endl;
    minHeapify(i,r);                 
}
            }
            else if(A[i][r] > A[l][j])
            {
                if(A[i][j] > A[l][j] ){
                swap(A[i][j], A[l][j]);
                //print();
                cout << "-----------------------------" << endl;
                minHeapify(l,j);
}
            }    
        }
    
    }   

};



int main()
{
    matriz m;
    //int A[N][M];
    m.inicia();
    m.ingresar();
    m.print();
    m.minHeapify(0,0);
    m.A[0][0]=INF;
    m.minHeapify(0,0);
    cout << "Segundo" <<endl;
    m.print();    
    m.A[0][0]=INF;
    //m.print();
    m.minHeapify(0,0);
    cout<<"Tercero" << endl;
    m.print();
    return 0;
    
}
