#include "function.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double Euler9(int mult_)
{
	for (double a = 0; a < mult_; a++)
	{
		for (double b = 0; b < a; b++)
		{
			double c = sqrt(pow(a, 2) + pow(b, 2));

			if ((a + b + c) == mult_)
			{
				return a * b * c;
			}
		}
	}
}

unsigned long long Euler8(char* number_, int size_, int amount_)
{
	unsigned long long res = 0;
	int temp = amount_;

	for (int i = 0; i < size_ - amount_; i++)
	{
		unsigned long long mult = 1;

		for (int j = i; j < temp; j++) 
		{
			mult *= number_[j] - '0';
		}
		temp++;

		if (mult > res)
		{
			res = mult;
		}
	}
	return res;
}

double Euler10(int max_)
{
	bool* arr = calloc(max_, sizeof(bool));

	for (int i = 2; i < max_; i++)
	{
		arr[i] = true;
	}

	for (int i = 2; i * i < max_; i++)
		if (arr[i] == true) {
			for (int j = i * i; j < max_; j += i)
				arr[j] = false;
		}
	double sum = 0;
	for (int i = 2; i < max_; i++)
	{
		if (arr[i] == true)
		{
			sum += i;
		}
	}
	free(arr);
	return sum;
}
