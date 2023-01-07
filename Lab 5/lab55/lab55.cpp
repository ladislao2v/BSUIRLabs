#include <iostream>
#include <conio.h>
#include <cstdio>
#include <math.h>
#include <cstdlib>

using namespace std;

int Input(int n)
{
    while (!(cin >> n) || cin.get() != '\n' || n < 1 || n > 10)
    {
        cout << "Error!" << endl << "Введите числовое значение = ";
        cin.clear();
        while (cin.get() != '\n');
    }
    return n;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    int a[10];

    cout << " Введите количество элементов массива от 0 до 10:" << endl;
    n = Input(n);
    cout << endl;

    cout << "Нажмите 1 - свои значения массива, Иначе - случайные " << endl;
    switch (_getch())
    {
    case '1':
        for (int i = 0; i < n; i++)
        {
            cout << "A" << i << " = ";
            while (!(cin >> a[i]) || cin.get() != '\n')
            {
                cout << "Error!" << endl << "Введите числовое значение = ";
                cin.clear();
                while (cin.get() != '\n');
            }
            cout << " Массив A" << i << " = " << a[i] << " " << endl;
        }
        break;
    default:
        cout << endl;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100 + 1;
            cout << " Массив A" << i << " = " << a[i] << " " << endl;
        }
    }
    cout << endl;

    int imin = 0, imax = 0;
    double prozv = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[imax] < a[i]) imax = i;
        if (a[imin] > a[i]) imin = i;
    }
    cout << "Max = " << a[imax] << endl;
    cout << "Min = " <<a[imin] << endl;

    if (imin > imax)
    {
        int m = imax;
        imax = imin;
        imin = m;
    }
    if (imax - imin == 1) cout << "Не существует";
    else {
        for (int i = imin + 1; i < imax; i++)
        {
            prozv = prozv * a[i];
        }
        cout << "Произведение элементов = " << prozv << endl;
    }
    system("pause");
}