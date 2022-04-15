#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

void CreateMatrix(int**, int);
void MatrixOutput(int**, int);
int FindAbsSum(int**, int);
int MinAbs(int, int, int);
void SortFunction(int**, int);

int main()
{
    setlocale (LC_ALL, "Russian");
    int m;
    int x;
    cout << "Введите размерность матрицы 1 и 3: ";
    cin >> m;   cout << endl;
    cout << "Введите размерность матрицы 2: ";
    cin >> x;   cout << endl;
    int **matrix_1 = new int *[m];
    int **matrix_2 = new int *[x];
    int **matrix_3 = new int *[m];
    
    srand(time(NULL));
    CreateMatrix(matrix_1, m);
    CreateMatrix(matrix_2, x);
    CreateMatrix(matrix_3, m);
    int absSum1 = FindAbsSum(matrix_1, m);
    int absSum2 = FindAbsSum(matrix_2, x);
    int absSum3 = FindAbsSum(matrix_3, m);
    int the_Smallest = MinAbs(absSum1, absSum2, absSum3);
    if (the_Smallest == absSum1)
    {
        SortFunction(matrix_1, m);
    }
    else if (the_Smallest == absSum2)
    {
        SortFunction(matrix_2, x);
    }
    else
    {
        SortFunction(matrix_3, m);
    }

    return 0;
}

void CreateMatrix(int **matrix, int size)
{
    for (int a=0; a < size; a++)
    {
        matrix[a] = new int [a];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() %  - 5;
        }
    }
    MatrixOutput(matrix, size);
}


void MatrixOutput(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "\n";
}

int FindAbsSum(int **matrix, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][0] < 0)
                {
                if (matrix[i][i] == matrix[j][j])
                {
                    sum += fabs(matrix[i][j]);
                }
                else if (i + j == size - 1)
                {
                    sum += fabs(matrix[i][j]);
                }
            }
        }
    }
    return sum;
}

int MinAbs(int first, int second, int third)
{
    if (first < second && first < third)
    {
        cout << "Наименьшая сумма принадлежит первой матрице = " << first << endl;
        return first;
    }
    else if (second < first && second < third)
    {
        cout << "Наименьшая сумма принадлежит второй матрице = " << second << endl;
        return second;
    }
    else
    {
        cout << "Наименьшая сумма принадлежит третьей матрице = " << second << endl;
        return third;
    }
}

void SortFunction(int **matrix, int size)
{
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < (size - 1); i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (matrix[k][j] > matrix[k][j + 1])
                {
                    int cell = matrix[k][j];
                    matrix[k][j] =  matrix[k][j+1];
                    matrix[k][j+1] = cell;
                    
                }
            }
        }
    }
    MatrixOutput(matrix, size);
}
