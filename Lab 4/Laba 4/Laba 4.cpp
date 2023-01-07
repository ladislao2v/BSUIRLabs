#include <iostream> 
#include <conio.h> 
#include <math.h> 

using namespace std;

typedef double (*Funtion) (double, int);

int VvodInteger(int n)
{
    cin.clear();
    while (!(cin >> n), (n < 1 || n>10) || cin.get() != '\n')
    {
        cout << "Ошибка!\nВведите правильное значение = ";
        cin.clear();
        while (cin.get() != '\n');
    }
    return n;
}

double VvodDouble(double i) 
{
    cin.clear();
    while (!(cin >> i), (i < 1 || i>15) || cin.get() != '\n')
    {
        cout << "Ошибка!\nВведите правильное значение = ";
        cin.clear();
        while (cin.get() != '\n');
    }
    return i;
}

double Y(double x, int n)
{
    return (1. + x * x) / 2. * atan(x) - (x / 2.);
}

double Summa(double x, int n)
{
    double s, r;
    s = r = x * x * x / 3.;
    for (int k = 2; k <= n; k++)
    {
        double f = 4. * k * k - 1.;
        r =  -r * (x * x) / f;
        s += r;
    }
    return s;
}

double ModulY_S(double x, int n)
{
    return abs(Y(x, n) - Summa(x, n));
}

void  Out_Rez(Funtion f, double a, double b, double h, int n)
{
    for (double x = a; x <= b; x += h)
        cout << "x = " << x << "\t res = " << f(x, n) << endl;
}

int main()
{
    double a = 0, b = 0, h = 0, PI = 3.1415926535;
    double x, s, r, lik;
    int n = 0;
    setlocale(LC_ALL, "Russian");
    cout << "Введите n = ";
    n = VvodInteger(n);
    cout << " 1 - Ввод с клавиатуры\n Другое - Стандартные значения" << endl;
    switch (_getch())
    {
    case '1':
        cout << "Введите начальный элемент промежутка = ";
        a = VvodDouble(a);
        cout << "Введите конечный элемент промежутка = ";
        b = VvodDouble(b);
        cout << "Введите шаг промежутка = ";
        h = VvodDouble(h);
        break;
    default:
        a = 0.1; 
        b = 1;
        h = 0.1;
        break;
    }
    cout << "Вывод результатов функции: " << endl;
    Out_Rez(Y, a, b, h, n);
    cout << "Вывод результатов суммы ряда: " << endl;
    Out_Rez(Summa, a, b, h, n);
    cout << "Вывод результатов разности суммы ряда и функции: " << endl;
    Out_Rez(ModulY_S, a, b, h, n);
    cout << "Программа выполнена" << endl;
    system("pause");
}