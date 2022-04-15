/*
C точностью ε = 10^-4
обчислить квадратный корень из случайного целого числа,
используя метод Ньютона:
Yn = (Y + (a / Y)) / 2, Y0 = 1;
 где а - целое число вводящееся пользователем.
Если a минусовое, тогда вывести соответсвующее сообщение.
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
 setlocale(LC_ALL, "Russian");
 int a;   // Целое число под корнем
 double Y = 1;
 double eps = 0.0001; // точность
 double dif; // Разница Yn-Y

 cout << "Введите а ( a - целое число ) : "; cin >> a;

 while (a < 0) {
  cout << "Вы ввели число а меньше 0, введите новое а: "; cin >> a;
 }

 do {
  double Yn = (Y + (a / Y)) / 2;
  dif = Yn - Y;
  Y = Yn;
 } while (abs(dif) >= eps);

 cout << "Y = " << Y << endl;

 system("pause");
}
