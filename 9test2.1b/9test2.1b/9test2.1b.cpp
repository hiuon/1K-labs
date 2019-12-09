#include <iostream>
#include <list>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct students
{
	char SurName[50];
	string Name;
	string Patronimic;
	string birthday;
	int course;
	int progress;
};

void add(vector<students>& db)
{
	students* nv = new students;
	cout << "\n-----------------------------------------------------------\n";
	cin.getline(nv->SurName, 29);
	cout << "Vvedite familiyu: "; cin.getline(nv->SurName, 50);
	cout << "Vvedite imya: "; getline(cin, nv->Name);
	cout << "Vvedite otchestvo: "; getline(cin, nv->Patronimic);
	cout << "Vvedite datu rojdeniya(01.01.2000): "; getline(cin, nv->birthday);
	cout << "Vvedite kurs: "; cin >> nv->course;
	cout << "Vvedite reiting uspevaemosti: "; cin >> nv->progress;
	db.push_back(*nv);
	delete nv;
}

void out(vector<students> db)
{
	vector<students>::iterator top = db.begin();
	while (top != db.end())
	{
		cout << setw(10) << top->SurName << setw(10) << top->Name << setw(10) << top->Patronimic << setw(10) << top->birthday << setw(10) << top->course << setw(10) << top->progress << '\n';
		top++;
	}
	cout << "\n";
}

void add(list<students>& db)
{
	students* nv = new students;
	cout << "\n-----------------------------------------------------------\n";
	cin.getline(nv->SurName, 29);
	cout << "Vvedite familiyu: "; cin.getline(nv->SurName, 50);
	cout << "Vvedite imya: "; getline(cin, nv->Name);
	cout << "Vvedite otchestvo: "; getline(cin, nv->Patronimic);
	cout << "Vvedite datu rojdeniya(01.01.2000): "; getline(cin, nv->birthday);
	cout << "Vvedite kurs: "; cin >> nv->course;
	cout << "Vvedite reiting uspevaemosti: "; cin >> nv->progress;
	db.push_back(*nv);
	delete nv;
}

void out(list<students> db)
{
	list<students>::iterator top = db.begin();
	while (top != db.end())
	{
		cout << setw(10) << top->SurName << setw(10) << top->Name << setw(10) << top->Patronimic << setw(10) << top->birthday << setw(10) << top->course << setw(10) << top->progress << '\n';
		top++;
	}
	cout << "\n";
}

int main()
{
	int n, k;
	vector<students> db;
	vector<students> bad_db;
	vector<students>::iterator p;
	
	cout << "Vvedite chislo studentov: "; cin >> n;
	cout << "Vvedite nomer kursa: "; cin >> k;

	for (int i = 0; i < n; ++i)
	{
		add(db);
	}
	out(db);
	unsigned start = time(0);
	p = db.begin();
	cout << "\n-----------------------------------------------------------\n";
	for (int i = 0; i < n; ++i)
	{
		int c = (p + i)->course;
		if (c == k && (p + i)->progress < 4)
		{
			bad_db.push_back(*(p + i));
			db.erase(p + i);
			p = db.begin();
			i--;
			n--;
		}
	}
	unsigned end = time(0);
	out(db);
	cout << "\n-----------------------------------------------------------\n";
	out(bad_db);
	cout << "\n-----------------------------------------------------------\n" << end  - start << '\n';
	
	list<students> db1;
	list<students> bad_db1;
	list<students>::iterator p1;
	cout << "Vvedite chislo studentov: "; cin >> n;
	cout << "Vvedite nomer kursa: "; cin >> k;

	for (int i = 0; i < n; ++i)
	{
		add(db1);
	}
	out(db1);
	start = time(0);
	p1 = db1.begin();
	cout << "\n-----------------------------------------------------------\n";
	while(p1 != db1.end())
	{
		if (p1->course == k && p1->progress < 4)
		{
			bad_db1.push_back(*p1);
			db1.erase(p1);
			p1 = db1.begin();
		}
		else
		{
			p1++;
		}
	}
	end = time(0);
	out(db1);
	cout << "\n-----------------------------------------------------------\n";
	out(bad_db1);
	cout << "\n-----------------------------------------------------------\n" << end - start << '\n';
}
