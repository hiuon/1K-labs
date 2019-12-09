#include <iostream>
#include <iomanip>

using namespace std;

struct chars
{
	char data;
	chars* next;
};

void add(chars*& L, char c)
{
	chars* nv, * ppv = L;
	nv = new chars;
	nv->next = NULL;
	nv->data = c;
	if (!L)
	{
		L = nv;
	}
	else
	{
		while (ppv->next)
		{
			ppv = ppv->next;
		}
		ppv->next = nv;
	}
}



void del(chars*& L, chars* s, chars* f)
{
	chars* ppv = L;
	bool check = false;
	if (L == s)
	{
		check = true;
	}
	while (ppv)
	{
		if (check)
		{
			while (s != f)
			{
				chars* tmp = s->next;
				delete s;
				s = tmp;
			}
			L = f->next;
			break;
		}
		else if (ppv->next == s)
		{
			chars* pv = ppv->next;
			chars* tmp = ppv->next;
			while (pv != f)
			{
				pv = pv->next;
				delete tmp;
				tmp = pv->next;
			}
			ppv->next = pv->next;
		}
		ppv = ppv->next;
	}
}

void solution(chars*& L, chars* L1)
{
	chars* ppv = L;
	chars* pv = L1;
	chars* start = NULL;
	chars* finish = NULL;
	bool check = false;
	while (ppv)
	{
		start = ppv;
		while (pv)
		{
			if (pv->data == ppv->data)
			{
				check = true;
				finish = ppv;
				pv = pv->next;
				ppv = ppv->next;
			}
			else
			{
				check = false;
				pv = L1;
				break;
			}
		}
		if (check)
		{
			del(L, start, finish);
			pv = L1;
		}

		if (ppv)
		{
			ppv = ppv->next;
		}
		else
		{
			break;
		}
	}
}

void out(chars* L)
{
	chars* pv = L;
	while (pv)
	{
		cout << "  " << pv->data;
		pv = pv->next;
	}
	cout << '\n';
}

int main()
{
	int n;
	chars* L = NULL;
	cout << "Vvedite chislo simvolov v L: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c;
		cout << "#" << i + 1 << ": ";
		cin >> c;
		add(L, c);
	}
	out(L);
	cout << "---------------------------------------\n";

	int n1;
	chars* L1 = NULL;
	cout << "Vvedite chislo simvolov v L1: "; cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		char c;
		cout << "#" << i + 1 << ": ";
		cin >> c;
		add(L1, c);
	}
	out(L1);
	cout << "---------------------------------------\n";

	solution(L, L1);
	out(L);
}