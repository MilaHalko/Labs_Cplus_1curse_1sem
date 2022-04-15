/* Дано действительное число х.
   Обчислить ((х-2)(x-4)(x-8)..(x-64)) / ((x-1)(x-3)(x-7)..(x-63)
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float x;
    cout << "Введите число, которое не равно 1, 3, 7, 15, 31, 63 : "; cin >> x;
    
    while (x==1 || x==3 || x==7 || x==15 || x==31 || x==63)
    {
        cout << "Ошибка! Введите другое число: "; cin >> x;
    }
    
    double sum1 = 1;
    for (int i=2; i<=64; i*=2)
        sum1 = sum1 * (x - i);
    
    double sum2 = 1;
    for (int i=2; i<=64; i*=2)
        sum2 = sum2 * (x - (i-1));
    
    double result = sum1 / sum2;
    cout<< "Результат: " << result << endl;
    
    return(0);
}

