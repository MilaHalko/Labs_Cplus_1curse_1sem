/*
 29. Натуральное число называется палиндромом,
     если его запись читается одинаково с начала и з конца (например, 4884, 575, 9).
     Найти все чотырехзначные палиндромы.
 */

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    setlocale(LC_ALL, "Russian");
    int i;
    int x;
    int num;
    int n = 0;  // число порядка
    
    cout << "Все полиндромные числа с 999 до 100000" << endl;
    
    for (i=1; i<=9; i++) {
        for (x=0; x<=9; x++) {
            n = n+1;
            num = i * pow(10, 3) + x * pow(10, 2) + x * 10 + i;
            
            if (n<=9) {
                cout << n << ")  " << num << endl;
            }
            else {
                cout << n << ") " << num << endl;
            }
        }
    }
    return (0);
}
