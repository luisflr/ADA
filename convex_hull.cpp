#include <iostream>
#include <stack>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;
#define N 100

ofstream os;


struct Point
{
	int x,y;
};

Point p0; //Punto global

//Funcion swap
int swap(Point &p1, Point &p2)
{
	Point temp= p1;
	p1 = p2;
	p2 = temp;
}

//Retornamos el next_to_top de la pila
Point next_to_top(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point temp = S.top();
	S.push(p);
	return temp;
}


//Distancia
double distancia(Point p1, Point p2)
{
//	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y); 
	double a = abs((p1.x * p2.x)+(p1.y * p2.y));
	double b = pow(p1.x,2) + pow(p1.y,2);
	double c = pow(p2.x,2) + pow(p2.y,2);
	double d = pow((b*c),0.5);
	double resultado = a/d ;
	return resultado;
}

//Orientación
int orientacion(Point p1, Point p2, Point p3) 
{ 
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y); 
    if (val == 0) return 0;  // colineal
    if (val > 0) return 1; //horario
    else return 2; // antihorario
} 

//Funcion de ordenamiento que compara todos con respecto a p0
//Retorna -1 cuando es antihorario
int comparacion(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;
	
	//Orientación
	int o = orientacion(p0,*p1,*p2);
	if (o == 0)
	{
		if(distancia(p0,*p2) >= distancia(p0,*p1))return -1;
		return 1;
	}
	if(o == 2) return -1;
	else return 1;
}
int partition(Point a[], int p, int r)
{
	Point x = a[r];
	int i = p - 1;
	for (int j = p; j <= r-1; j++)
	{
		if(a[j].y <= x.y)
		{
			i = i + 1;
			swap(a[j], a[i]);
			
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

void quick_sort(Point a[], int p, int r)
{
	if( p < r)
	{
		int q = partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
		
	}
}

void convex_hull(Point points[])
{
	//Encontramos el punto minimo
	int ymin = points[0].y;
	int min = 0;
	for (int i=0;i<N;i++)
	{
		int y = points[i].y;
		if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) 
		{
			ymin= points[i].y;
			min = i;	
		}
		
	}
	//Intercambiamos el punto minimo por el punto en la primera posicion
	swap (points[0],points[min]);
	// Ordenamos n-1 puntos con respecto al primer punto
	p0 = points[0];
	// Valor negativo si el primer argumento es menor que el segundo
	// Valor positivo si el primer argumento es mayor que el segundo
	// Valor 0 si son iguales
	//quick_sort(points,0, N -1);
	//for(int i = 0; i<N; i++)
	//{
	//	cout<<"("<<points[i].x << ","<<points[i].y<<")"<<endl;
	//}
	//cout<<"ordeno?"<<endl;
	qsort  (&points[1],N-1,sizeof(Point),comparacion); 
	//Si dos puntos tienen el mismo angulo con p0, nos quedamos con el más alejado
	//Inicializamos el array modificado
	int m=1;
	for (int i=1;i<N;i++)
	{
		//Eliminamos i mientras que el angulo de i e i+1 es el mismo, eliminamos colineales
		while(i < N-1 && orientacion(p0, points[i], points[i+1])==0) // 0 es colineales
			i++;
		points[m] = points[i];
		m++; //aumentamos el tamaño del nuevo array
	}
	
	//Si el array nuevo es menor que 3, no se puede hacer convex
	if(m < 3) return;
	
	//Creamos la pila y añadimos los tres primeros puntos
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);
	//Empezamos con los siguientes puntos
	for (int i=3; i<m;i++)
	{
		//Seguimos quitando el top de la pila mientras que el angulo 
		//formado por los puntos "next_to_top", "top", "points[i]" no sean antihorarios
		while(orientacion(next_to_top(S),S.top(),points[i])!= 2) 
			S.pop();
		S.push(points[i]);
	}
	
	os.open("respuesta.txt");
	Point tmp = S.top();
	//Imprimimos la pila
	while (!S.empty())
	{
		Point p = S.top();
		cout << "(" << p.x << "," << p.y << ")" << endl;
		os << p.x <<'\t'<< p.y << endl;
		S.pop();	
	}	
	os<<tmp.x<<'\t'<<tmp.y<<endl;
	os.close();
}



int main()
{
	Point points[N];
	ofstream os2;
	for (int i=0;i<N;i++)
	{
		points[i].x = rand()%10;
		points[i].y = rand()%10;
	}
	os2.open("puntos.txt");
	for (int i=0;i<N;i++)
	{
		os2<< points[i].x <<'\t'<< points[i].y<< endl;
	}
	os2.close();	
	
	convex_hull(points);
	
	return 0;
}

