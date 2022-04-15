#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

void array_Output(double*, int, int);
void array_Rand(double*, double*, int);
void array_C(double*, double*, double*, int);
void array_C_New(double*, int);
double array_C_Average(double*, int);


int main()
{
	setlocale(LC_ALL, "Russian");
	
	int length;
	cout << "Введите длину массива: "; cin >> length; cout << endl;
	double *A = new double[length];
	double *B = new double[length];
	double *C = new double[length];
	
	array_Rand(A, B, length);
	array_Output(A, length, 1);
	array_Output(B, length, 2);
	array_C(A, B, C, length);

	delete[]A;
	delete[]B;

	array_Output(C, length, 3);
	array_C_New(C, length);
	array_Output(C, length, 3);

	delete[]C;

	return 0;
}

void array_Rand(double A[], double B[], int length)
{

	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		A[i] = (rand() % 100) * 0.1;
		B[i] = (rand() % 100) * 0.1;
	}
}


void array_Output(double *array, int length, int number)
{
	cout << "Массив_" << number << ": ";
	{
		for (int i = 0; i < length; i++)
		{
			cout << setw(10) << left << array[i];
		}
		cout << endl << endl;
	}
}


void array_C(double *A, double *B, double* C, int length)
{
	for (int i = 0; i < length; i++)
	{
		C[i] = abs(pow(A[i], 2) - pow(B[i], 2));
	}

}

void array_C_New(double *C, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (C[i] > C[i + 1])
		{
			C[i], C[i + 1] = C[i + 1], C[i];
		}

	}
	C[length - 1] = array_C_Average(C, length);
}

double array_C_Average(double *C, int length)
{
	double multuplier = 0;
	for (int i = 0; i < length; i++)
	{
		multuplier = C[i] + multuplier;
	}
	float average = multuplier / length;
	cout << "Среднее арифметическое элементов массива_3 = " << average << endl << endl;
	return average;
}