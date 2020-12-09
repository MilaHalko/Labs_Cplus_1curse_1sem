/*
    Заданны неотрицательные целые числа n и M.
    Вычислить функцию Аккермана пользуясь следующими рекуррентными соотношениями:
    A(n,m) = m+1,  якщо n=0;
    A(n,m) = A(n-1,1),  якщо n>0, m=0;
    A(n,m) = A(n-1, A(n,m-1)),  якщо n>0, m>0
 */

#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void input(int*n,int*m)
{
    cout << "Введите целые неотрицательные n и m:" << endl << "n="; cin >> *n; cout << "m="; cin >> *m; cout << endl;
}

void error(int *n, int *m)
{
    while (*n<0){
        cout << "Введите целое неотрицательное n: "; cin >> *n;
    }
    while (*m<0){
        cout << "Введите целое неотрицательное m: "; cin >> *m;
    }
}

int A (int n,int m)
{
    int F;
    if (n>0 && m>0){
        F = A(n-1, A(n,m-1));
    }
    else if (n>0 && m==0){
        F = A(n-1,1);
    }
    else {
        F = m+1;
    }
    return F;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int n;
    int m;
    int res;
    
    input(&n,&m);   // Ввод целых неотрицательных чисел n, m
    if (n<0 || m<0)
        error(&n,&m);
    res = A (n,m);
    cout << res << endl;
    return 0;
}
    

