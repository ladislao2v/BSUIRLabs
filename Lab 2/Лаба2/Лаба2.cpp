#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y, f, res, usl;

    cout << " Введите х = ";
    cin >> x;
    cout << " Введите y = ";
    cin >> y;

    cout << " Выберите f(x): 1 - sinh()\n2 - x^2, 3 - exp(x)\nElse - f(x)=|x|^1/3 " << endl;
    switch (_getch())
    {
    case 1: f = sinh(x); cout << "Выбрана f(x)=sinh(x)" << endl;
        break;
    case 2: f = pow(x, 2); cout << "Выбрана f(x)=x^2" << endl;
        break;
    case 3: f = exp(x); cout << "Выбрана f(x)=exp(x)" << endl;
        break;
    default: cout << "Функция не выбрана!!! => f(x)=|x|^1/3";
        f = pow(abs(x), 1. / 3.);
    }
    usl = x * y;
    if (usl < 0)
    {
        res = pow((f + y), 2) - pow(abs(f), 1. / 3.);
        cout << " При условии xy<0" << endl;
    }
    else if (usl > 0)
    {
        res = pow((f + y), 2) + sin(x);
        cout << " При условии xy>0" << endl;
    }
    else
    {
        res = pow((f + y), 2) + pow(y, 3);
        cout << " При условии xy=0" << endl;
    }
    cout << " Ваш результат = " << res << endl;
    system("pause");
}
