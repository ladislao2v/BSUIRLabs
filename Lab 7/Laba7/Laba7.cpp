#include <string.h>
#include <iostream>
#include <conio.h>
#include <istream>
#include <stdlib.h>
#include <string>

using namespace std;

void InputString(char* s)
{
	int i = 0;
	while (1) {
		s[i] = _getch();
		if (s[0] == ' ') continue;
		if (s[i] == 13) break;
		if (!(s[i] == '0' || s[i] == '1' || s[i] == ' '))
			continue;
		cout << s[i];
		i++;
	}
	s[i] = '\0';
}


int main()
{
	setlocale(LC_ALL, "Russian");
	char string[255] = "\0";
	char group[6] = "\0";
	char exampleString[255] = "10100 101 0101010101 00000 11111 1010 101010 11111";
	int n = 0, lenth, groups = 0, position;
	cout << "1 - Ввести свою строку, Остальное - заготовленная строка" << endl;
	if (_getch() == '1')
	{
		cout << "Введите текст строки: ";
		InputString(string);
	}
	else 
		strcpy_s(string, exampleString);
  lenth = strlen(string);

  cout << "\nВаша строка: " << string << endl;
  cout << "Найденные группы: " << endl;
  for (int i = 0; i <= lenth-1; i++)
  {
	  if (string[i] != ' ') 
		  n++;
	  else if (string[i] == ' ') 
		  n = 0;
	  if (n == 5 && (string[i + 1] == ' ' || string[i + 1] == '\0'))
	  { 
		  n = 0; 
		  groups++;
		  position = i - 4;
	      strncpy_s(group, string + position, 5);
		  cout << group << ' ' << endl;;
	  }
  }
  cout << "\nИ их количество : "  << groups << '\n';
  system("pause");
}