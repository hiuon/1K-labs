#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

struct St
{
	string SurName;
	string Name;
	string Patronimic;
	bool isMan;
	int age;
	int course;
	bool progress;
};

struct St_bin
{
	char SurName[30];
	char Name[30];
	char Patronimic[30];
	bool isMan;
	int age;
	int course;
	bool progress;
};

void create_db(fstream &gl, fstream &glb, ifstream &no_emp)
{
	char check;
	cout << "Vnesti v bazu uje imeuschiysya spisok?(y/n): "; cin >> check;
	if (check == 'y')
	{
		St student;
		St_bin studentb;
		do
		{
			getline(no_emp, student.SurName, ' ');
			strcpy_s(studentb.SurName, student.SurName.c_str());
			getline(no_emp, student.Name, ' ');
			strcpy_s(studentb.Name, student.Name.c_str());
			getline(no_emp, student.Patronimic, ' ');
			strcpy_s(studentb.Patronimic, student.Patronimic.c_str());
			no_emp >> student.isMan >> student.age >> student.course >> student.progress;
			studentb.isMan = student.isMan;
			studentb.age = student.age;
			studentb.course = student.course;
			studentb.progress = student.progress;
			gl << student.SurName << ' ' << student.Name << ' ' << student.Patronimic << ' ' << student.isMan << ' ' << student.age << ' ' << student.course << ' ' << student.progress << '\n';
			glb.write((char*)&studentb, sizeof(studentb));
			getline(no_emp, student.SurName);
		} while (!no_emp.eof());
	
	}
	int k;
	cout << "Vvedite chislo vnosimikh studentov: "; cin >> k;
	for (int i = 0; i < k; i++)		
	{
		St_bin studentb;
		string out;
		cout << "Vvedite familiu: "; cin >> out; gl << out << ' ';
		strcpy_s(studentb.SurName, out.c_str());
		cout << "Vvedite imya: "; cin >> out; gl << out << ' ';
		strcpy_s(studentb.Name, out.c_str());
		cout << "Vvedite otchestvo: "; cin >> out; gl << out << ' ';
		strcpy_s(studentb.Patronimic, out.c_str());
		cout << "Vvedite pol(m/w): "; cin >> out; 
		if (out == "m")
		{
			gl << "1 ";
			studentb.isMan = 1;
		}
		else
		{
			gl << "0 ";
			studentb.isMan = 0;
		}
		cout << "Vvedite vozrast: "; cin >> out; gl << out << ' ';
		studentb.age = atoi(out.c_str());
		cout << "Vvedite kurse: "; cin >> out; gl << out << ' ';
		studentb.course = atoi(out.c_str());
		cout << "Vvedite uspevaemost'(0/1): "; cin >> out; gl << out << '\n';
		studentb.progress = atoi(out.c_str());
		glb.write((char*)&studentb, sizeof(studentb));
		if (i != k - 1)
		{
			gl << '\n';
		}
		cout << "-----------------------------------------------------------\n";
	}
	gl.seekg(0, ios::beg);
	gl.clear(); 
	glb.seekg(0, ios::beg);
	glb.clear();
	no_emp.seekg(0, ios::beg);
	no_emp.clear();
}

void find_bad(fstream &in, fstream &Global, int k)
{
	St student;
	do
	{
		getline(Global, student.SurName, ' ');
		getline(Global, student.Name, ' ');
		getline(Global, student.Patronimic, ' ');
		Global >> student.isMan >> student.age >> student.course >> student.progress;
		if (k == student.course && !student.progress && !Global.eof())
		{
			in << student.SurName << ' ' << student.Name << ' ' << student.Patronimic << endl;
		}
		getline(Global, student.SurName);
	} while (!Global.eof());
	in.seekg(0, ios::beg);
	Global.seekg(0, ios::beg);
	in.clear();
	Global.clear();
}

void write_bad(fstream &in)
{
	string out;
	while (getline(in, out))
	{
		cout << out << '\n';
	}
}

void find_bad_bin(fstream &in, fstream &Global, int k)
{
	do
	{
		St_bin student;
		Global.read((char*)&student, sizeof(student));
		if (Global.eof())
		{
			break;
		}
		if (!student.progress && student.course == k)
		{
			in.write((char*)&student, sizeof(student));
		}
	} while (!Global.eof());
	in.seekg(0, ios::beg);
	in.clear();
}

void write_bad_bin(fstream &in)
{
	St_bin student;
	do
	{
		in.read((char*)&student, sizeof(student));
		if (in.eof())
		{
			break;
		}
		cout << student.SurName << ' ' << student.Name << ' ' << student.Patronimic << '\n';
	} while (!in.eof());
}

int main()
{
	int k;
	cout << "Vvedite nomer kursa: ";
	cin >> k;
	ifstream No_empty_db("Students_create.txt");
	fstream Global("Students.txt", ios::out);
	fstream Global_bin("Students.bin", ios::out | ios::binary);
	fstream in("Bad_students.txt", ios::out);
	fstream in_Bin("Bad_students.bin", ios::out | ios::binary);

	create_db(Global, Global_bin, No_empty_db);
	if (!in || !in_Bin || !Global)
	{
		cout << "Error";
		return 1;
	}

	Global.close();
	Global_bin.close();

	Global.open("Students.txt", ios::in);
	find_bad(in, Global, k);
	in.close();
	
	in.open("Bad_students.txt", ios::in);
	cout << "-----------------------------------------------------------\n";
	write_bad(in);
	Global.close();

	cout << "-----------------------------------------------------------\n";

	Global_bin.open("Students.bin", ios::in | ios::binary);
	find_bad_bin(in_Bin, Global_bin, k);
	in_Bin.close();
	in_Bin.open("Bad_students.bin", ios::in | ios::binary);
	write_bad_bin(in_Bin);
	cout << "-----------------------------------------------------------\n";
	Global.close();
	system("pause");
}