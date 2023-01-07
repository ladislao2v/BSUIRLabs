#include <iostream>
#include <conio.h>
#include <math.h>
#define pi 3.14159265


using namespace std;

double Result(double x, double y, double z)
{
	return (2 * cos(x - pi / 6)) / (0.5 + sin(y) * sin(y)) * (1 + (z * z / (3 - z * z / 5)));
}

double Choise(double *x, double *y, double *z)
{
	switch (_getch())
	{
	case '1':
		*x = 14.26;
		*y = -1.22;
		*z = 3.5 * 0.01;
		break;
	default:
		cout << "Введите x, y, z" << endl;
		cin >> *x;
		cin >> *y;
		cin >> *z;
		break;
	}
	return x, *y, *z;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x, z, y;

	cout << "Стандартные значения или ввод с клавиатуры?" << endl;
	cout << "1 - Да\n2 - Нет" << endl;
	Choise(&x, &y, &z);

	cout << "Результат вычесления: " << Result(x, y, z);
}
