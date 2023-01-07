#include <iostream>
#include <conio.h>
#include <fstream>
#include "Student.cpp"
#include <vector>
#include <string>
#include <Windows.h>
#include <utility>

using namespace std;

double SetAverageMark(Student student)
{
	return (student.mathMark + student.chemistryMark + student.physicsMark + student.itMark) / 4.;
}

void Localization()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
}

void SaveToFile(Student student)
{
	ofstream out("student.stnd", ios::app);

	if (out.is_open())
	{
		out << student.name << "\n" << student.groupNumber << "\n" << student.mathMark << "\n" << student.chemistryMark << "\n" << student.physicsMark << "\n" << student.itMark << "\n" << student.averageMark << "\n" << endl;
	}
	out.close();
}

vector<string> LoadForFile(vector<string> fileInfo)
{
	string line;
	bool isFull = true;
	int i = 0;

	ifstream fs("Student.stnd", ios::in | ios::binary);
	while (!fs.eof())
	{
		getline(fs, line);
		fileInfo.push_back(line);
	}
	fileInfo.push_back("\n");
	fs.close();
	return fileInfo;
}

Student InputStudent()
{
	Student student;
	cout << "Введите имя студента: ";
	cin.getline(student.name, 81, '+');
	if (student.name[0] == '\n')
		student.name[0] = ' ';
	cout << "Введите группу студента: ";
	cin >> student.groupNumber;
	cout << "Введите оценку по математике студента: ";
	cin >> student.mathMark;
	cout << "Введите оценку по химии студента: ";
	cin >> student.chemistryMark;
	cout << "Введите оценку по физике студента: ";
	cin >> student.physicsMark;
	cout << "Введите оценку по информатике студента: ";
	cin >> student.itMark;
	student.averageMark = SetAverageMark(student);
	return student;
}

vector<Student> GetStudent(vector<string> fileInfo)
{
	vector<Student> studentInFile;
	Student student;
	int j = 0;
	for (int i = 0; i < fileInfo.size() / 8; i++)
	{
		strcpy_s(student.name, fileInfo[j++].c_str());
		student.groupNumber = atoi(fileInfo[j++].c_str());
		student.mathMark = atoi(fileInfo[j++].c_str());
		student.chemistryMark = atoi(fileInfo[j++].c_str());
		student.physicsMark = atoi(fileInfo[j++].c_str());
		student.itMark = atoi(fileInfo[j++].c_str());
		student.averageMark = atoi(fileInfo[j++].c_str());
		j += 1;
		studentInFile.push_back(student);
	}
	return studentInFile;
}

void StudentInfo(Student student, int i)
{
	cout << i + 1 << ". Имя студента: " << student.name << endl;
	cout << "   Группа студента: " << student.groupNumber << endl;
	cout << "   Оценка по матетематике: " << student.mathMark << endl;
	cout << "   Оценка по химии: " << student.chemistryMark << endl;
	cout << "   Оценка по физике: " << student.physicsMark << endl;
	cout << "   Оценка по ОАиП: " << student.itMark << endl;
	cout << "   Ср. б. студента: " << student.averageMark << endl;
}

int main()
{
	Localization();

	vector<Student> studentsPerSession;
	vector<string> fileInfo;
	vector<Student> studentInFile;

	while (true)
	{
		cout << "1.Создать ученика\n2.Список учеников" << endl;
		cout << "3.Добаленные за сеанс" << endl;
		cout << "4.Коррекция данных ученика\n5.Удалить ученика" << endl;

		switch (_getch())
		{
		case '1':
			Student student = InputStudent();
			studentsPerSession.push_back(student);
			SaveToFile(student);
			break;
		case '2':
			fileInfo = move(LoadForFile(fileInfo));
			studentInFile = move(GetStudent(fileInfo));
			for (int i = 0; i < studentInFile.size(); i++)
				StudentInfo(studentInFile[i], i);
			break;
		case '3':
			if (!studentsPerSession.empty())
				for (int i = 0; i < studentsPerSession.size(); i++)
					StudentInfo(studentsPerSession[i], i);
			else
				cout << "\nНовых студентов нет!\n" << endl;
			break;
		case '4':
			cout << "В разработке" << endl;
			break;
		case '5':
			fileInfo = move(LoadForFile(fileInfo));
			cout << "На данный момент в базе " << fileInfo.size() / 8 << " студента" << endl;
			

			break;
		default:
			system("cls");
		}
	}
}