// InfP2Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

void randArr(int *arr, int n);
void outputArr(int *arr, int n);
void shekerSort(int *l, int *r);

void main()
{
	const int n = 10;
	int arr[n];
	randArr(arr, n);
	outputArr(arr, n);
	shekerSort(arr, arr + n - 1);
	outputArr(arr, n);
}

void randArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void outputArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void shekerSort(int *l, int *r)
{	
	int flag = 1;
	while (l < r && flag > 0)
	{
		flag = 0;
		for (int *i = l; i < r; i++)
		{
			if (*i>*(i + 1))
			{
				int t = *i;
				*i = *(i + 1);
				*(i + 1) = t;
				flag = 1;
			}
		}
		r--;
		for (int *i = r; i>l; i--)
		{
			if (*(i-1)>*i)
			{
				int t = *i;
				*i = *(i-1);
				*(i-1) = t;
				flag = 1;
			}
		}
		l++;	
	}
}