#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

struct students
{
	char SurName[50];
	string Name;
	string Patronimic;
	string birthday;
	int course;
	int progress;
	students* next;
};

void find_gt(students *top, char str[], students *&ppv)
{
	students* pv = top;
	ppv = top;
	while (pv && strcmp(pv->SurName, str) <= 0) 
	{
		ppv = pv; 
		pv = pv->next;
	}
}

void find_eq(students *top, students *&pv, int k)
{
	students* temp = top;
	pv = NULL;
	while (!pv && temp)
	{
		if (temp->course == k)
		{
			if (temp->progress < 4)
			{
				pv = temp;
			}
		}
		temp = temp->next;
	}
}

void out(students* top)
{
	while (top)
	{
		cout << setw(10) << top->SurName << setw(10) << top->Name << setw(10) << top->Patronimic << setw(10) << top->birthday << setw(10) << top->course << setw(10) << top->progress << '\n';
		top = top->next;
	}
	cout << "\n";
}

void add(students *&top)
{
	students *nv, *ppv = NULL;
	nv = new students;
	nv->next = NULL;
	cout << "\n-----------------------------------------------------------\n";
	cin.getline(nv->SurName, 29);
	cout << "Vvedite familiyu: "; cin.getline(nv->SurName, 50);
	cout << "Vvedite imya: "; getline(cin, nv->Name);
	cout << "Vvedite otchestvo: "; getline(cin, nv->Patronimic);
	cout << "Vvedite datu rojdeniya(01.01.2000): "; getline(cin, nv->birthday);
	cout << "Vvedite kurs: "; cin >> nv->course;
	cout << "Vvedite reiting uspevaemosti: "; cin >> nv->progress;
	if (!top)
	{
		top = nv;
	}
	else
	{
		if (strcmp(top->SurName, nv->SurName) >= 0)                   
		{
			nv->next = top;
			top = nv;
		}
		else
		{
			find_gt(top, nv->SurName, ppv);
			nv->next = ppv->next; 
			ppv->next = nv;
		}
	}
}

void add(students*& bad, students* pv)
{
	students* temp = new students;
	students* ppv = NULL;
	temp->next = NULL;
	strcpy_s(temp->SurName, pv->SurName);
	temp->Name = pv->Name;
	temp->Patronimic = pv->Patronimic;
	temp->birthday = pv->birthday;
	temp->course = pv->course;
	temp->progress = pv->progress;
	if (!bad)
	{
		bad = temp;
	}
	else
	{
		if (strcmp(bad->SurName, temp->SurName) >= 0)
		{
			temp->next = bad;
			bad = temp;
		}
		else
		{
			find_gt(bad, temp->SurName, ppv);
			temp->next = ppv->next;
			ppv->next = temp;
		}
	}
}

void del(students*& top, students*& bad, int k)
{
	students* pv;
	find_eq(top, pv, k);
	if (pv)
	{
		add(bad, pv);
		if (top = pv)
		{
			top = top->next;
			delete pv;
		}
		else
		{
			students* temp = top;
			while (temp->next != pv)
			{
				temp = temp->next;
			}
		temp->next = pv->next;
		delete pv;
		}
	}
}


int main()
{
	students* top = NULL;
	students* bad = NULL;
	int n, k;
	cout << "Vvedite chislo studentov: "; cin >> n;
	cout << "Vvedite nomer kursa: "; cin >> k;
	for (int i = 0; i < n; i++)
	{
		add(top);
	}
	out(top);
	for (int i = 0; i < n; i++)
	{
		del(top, bad, k);
	}
	cout << "\n-----------------------------------------------------------\n";
	out(top);
	cout << "\n-----------------------------------------------------------\n";
	out(bad);
	system("pause");
}