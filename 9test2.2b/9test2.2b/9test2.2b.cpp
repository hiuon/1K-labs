#include <iostream>
#include <vector>
#include <list>

using namespace std;

void solution(vector<char>& L, vector<char> L1)
{
	bool check = false;
	int start;
	int finish;
	for (int i = 0; i < L.size(); ++i)
	{
		start = i;
		for (int j = 0; j < L1.size(); ++j)
		{
			if (L1[j] == L[i])
			{
				check = true;
				finish = i;
				i++;
				if (i == L.size() && j + 1 != L1.size())
				{
					check = false;
					break;
				}
			}
			else
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			L.erase(L.begin() + start, L.begin() + finish + 1);
			i = -1;
		}
	}
}

void enter(vector<char>& L)
{
	for (int i = 0; i < L.size(); i++)
	{
		cout << "#" << i + 1 << ": ";
		cin >> L[i];
	}
}

void out(vector<char>& L)
{
	cout << "\n---------------------------------------\n";
	for (int i = 0; i < L.size(); i++)
	{
		cout << L[i];
	}
	cout << "\n---------------------------------------\n";
}

void enter(list<char>& l)
{
	list<char>::iterator p = l.begin();
	for (int i = 0; p != l.end(); i++, p++)
	{
		cout << "#" << i + 1 << ": ";
		cin >> *p;
	}
}

void out(list<char>& l)
{
	list<char>::iterator p = l.begin();
	cout << "\n---------------------------------------\n";
	for (; p != l.end(); p++)
	{
		cout << *p;
	}
	cout << "\n---------------------------------------\n";
}

void solution(list<char>& L, list<char> L1)
{
	bool check = false;
	list<char>::iterator start = L.begin();
	list<char>::iterator finish = L.begin();
	while (start != L.end())
	{
		list<char>::iterator start1 = L1.begin();
		while(start1 != L1.end())
		{
			if (*start1 == *start)
			{
				check = true;
				start1++;
				start++;
				if (start == L.end())
				{
					if (start1 == L1.end())
					{
						break;
					}
					else
					{
						check = false;
						finish = start;
						break;
					}
				}
			}
			else
			{
				finish++;
				check = false;
				break;
			}
		}
		if (check)
		{
			L.erase(finish, start);
			finish = start;
		}
		else
		{
			start = finish;
		}
	}
}

int main()
{
	int n, n1;

	cout << "Vvedite chislo simvolov v L: "; cin >> n;
	vector<char> L(n);
	enter(L);
	out(L);
	cout << "Vvedite chislo simvolov v L1: "; cin >> n1;
	vector<char> L1(n1);
	enter(L1);
	out(L1);
	solution(L, L1);
	out(L);

	cout << "Vvedite chislo simvolov v L: "; cin >> n;
	list<char> l(n);
	enter(l);
	out(l);
	cout << "Vvedite chislo simvolov v L1: "; cin >> n1;
	list<char> l1(n1);
	enter(l1);
	out(l1);
	solution(l, l1);
	out(l);
}