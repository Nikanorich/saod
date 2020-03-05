#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <nmmintrin.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <cmath>
#include <climits>
#include <bitset>
#include <random>
#include <ctime>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <sstream>
using namespace std;
void CalcMC(int n)
{
	int m, c;
	m = 3*(n - 1);
	c = (pow(n, 2) - n)/2;
	cout << "M teoreticheskaya ravna " << m << endl << "C teoreticheskaya ravna " << c; 
}
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int n, int *a)  
{  
    int i, j, min_idx, m = 0, c = 0;
    for (i = 0; i < n-1; i++)  
    {    
        min_idx = i;  
        for (j = i+1; j < n; j++) 
		{
		c++;  
        if (a[j] < a[min_idx])  
        min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&a[min_idx], &a[i]);
			m+=3;  
		} 
    }
	cout << endl;
	cout << "C fact ravno " << c << endl << "M fact ravno " << m;   
}  
int RunNumber(int n, int *a)
{
	int num = 1;
	int null = a[0];
	for(int i = 1; i < n; i++)
	{
		if (a[i] < null)
		{
			num++;
		}
		null = a[i];
	}
	return num;
}
int CheckSum(int n, int *a)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum+=a[i];
	}
	return sum;
}
void FillRand(int n, int *a)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
void FillDec(int n, int *a)
{
	for (int i = n; i > 0; i--)
	{
		a[n - i] = i;
	}	
}
void PrintMas(int n,int *a) 
{
  for (int i = 0; i < n;++i)
  {
    cout << a[i]<<" ";
  }
}
void FillInc(int n,int *a) 
{
  for (int i = 0; i < n;++i)
  {
	a[i] = i; 
  }
}
void CheckRand(int n, int *a)
{
	for(int i = 1; i < 10; i++)
	{
		FillRand(n, a);
		cout << endl << "Длина серии" << " " << i << " = " << RunNumber(n, a);	
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	int *A = new int[n];
	cin >> n;
	FillRand(n, A);
	PrintMas(n, A);
	cout << endl << CheckSum(n, A);
	cout << endl << RunNumber(n, A);
	selectionSort(n, A);
	cout << endl;
	PrintMas(n, A);
	cout << endl << CheckSum(n, A);
	cout << endl << RunNumber(n, A);
	cout << endl;
	CalcMC(n);
	FillDec(n, A);
	cout << endl;
	PrintMas(n, A);
	selectionSort(n, A);
	cout << endl;
	PrintMas(n, A);
	FillInc(n, A);
	cout << endl;
	PrintMas(n, A);
	selectionSort(n, A);
	cout << endl;
	PrintMas(n, A);	
}
