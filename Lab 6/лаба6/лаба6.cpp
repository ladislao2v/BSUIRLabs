#include <iostream>
#include <conio.h>
#include <math.h>
#include <istream>

using namespace std;


int Input(int x)
{
    cin.clear();
    while (!(cin >> x), x<1 || cin.get() != '\n')
    {
        cout << "Error!" << endl << "Введите правильное значение = ";
        cin.clear();
        while (cin.get() != '\n');
    }
    return x;
}

int main()
{
    system("color 2");
    setlocale(LC_ALL, "Russian");
    double **a, *b, B;
    int i, j, k, n = 0, m = 0;
    cout << "Введите количество строк = ";
    n = Input(n);
    cout << "Введите количество столбцов = ";
    m = Input(m);

    a = new double*[n];
    for (i = 0; i < n; i++) 
        a[i] = new double[m];
    b = new double[m];
    cout << "1 - Ввод с клавиатуры, иначе - случайные значения" << endl;
    if (_getch() == '1')
    {
        cout << "Введите элементы массива: " << endl;
        for (i = 0; i < n; i++) for (j = 0; j < m; j++)
        {
            cout << "A" << i + 1 << j + 1 << " = ";
            while (!(cin >> a[i][j]) || cin.get() != '\n')
            {
                cout << "Error!" << endl << "Введите правильное значение = ";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
    }
    else 
    {
        srand(time(NULL));
        for (i = 0; i < n; i++)
            for (j=0; j<m;j++)
            {
               a[i][j] = rand() % 21 - 10;
            }
    }

    cout << "Ваша Матрица: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Ваш Вектор В: " << endl;
    for (j = 0; j < m; ++j)
    {
        b[j] = 0;
        for (i = 0; i < n; ++i)
        {
            if (a[i][j] != 0) {
                b[j] = 1;
                break;
            }
        }
        cout << b[j] << " ";
    }
    cout << endl;

    for (i = 0; i < n; ++i) delete[]a[i];
    delete []a;
    delete[]b;
    system("pause");
}