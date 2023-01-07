#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Нажмите 1 - для выбора стандартных значений, ИНАЧЕ - для ввода с клавиатуры." << endl;

    long double a, b, h, x, r, s;
    long int n, k;

    if (_getch() == '1')
    {
        a = 0.1;
        b = 1;
        h = 0.1;
        cout << "Вы выбрали стандартные значения a=0.1 , b=1 , h=0.1 " << endl;
    }
    else
    {
        cout << "Введите a = ";
        cin >> a;
        cout << "Введите b = ";
        cin >> b;
        cout << "Введите h = ";
        cin >> h;
    }

    cout << "Введите n = ";
    cin >> n;

    for (x = a; x <= b; x += h)
    {
        r = s = x;
        for (k = 1; k <= n; k++)
        {
            r = -r * x * x / ((2 * k) * (2 * k + 1));
            s += r;
        }
        long double y = sin(x);
        long double mod = fabs(y - s);
        cout << "При x=" << x << " --- S(x)=" << s << " и Y(x)=" << y << " ,а также |Y(x)-S(x)|=" << mod << endl;
    }
    cout << "Программа выполнена" << endl;
}