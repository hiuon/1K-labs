#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Aud_t
{
	unsigned char number : 5;
	unsigned char floor : 3;
};

union Aud_u
{
	unsigned char cod;
	Aud_t aud;
};
void create_mas(Aud_u &AUD)
{
	AUD.aud.floor = rand() % 8;
	AUD.aud.number = rand() % 32;
	cout << " Floor: " << +AUD.aud.number + 1 << "; Number: " << +AUD.aud.number + 1 << endl;
}

void check_and_out(Aud_u AUD[], const int n, char *check)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (AUD[i].aud.floor == AUD[j].aud.floor)
			{
				if (check[j] == 3)
				{
					break;
				}
				if (AUD[i].aud.number == AUD[j].aud.number)
				{
					check[i] = 2;
					check[j] = 3;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] == 2)
		{
			cout << "Floor: " << +AUD[i].aud.floor + 1 << "; Number: " << +AUD[i].aud.number + 1<< endl;
		}
	}
}

void out(union Aud_u &AUD)
{
	cout << " Floor: " << +AUD.aud.floor + 1 << "; Number: " << +AUD.aud.number + 1 << endl;
}

int main()
{
	srand((unsigned)time(0));
	const unsigned int n = 100;
	Aud_u AUD[n];
	char check[n] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1;
		create_mas(AUD[i]);
	}
	sort(AUD, AUD + sizeof(AUD) / sizeof(AUD[0]), [](const Aud_u&a, const Aud_u&b)
	{
		return a.cod < b.cod;                                                                                                          //(a.floor < b.floor) ? true : (a.floor > b.floor) ? false : (a.number < b.number);
	});
	cout << "\n-------------------------------------------------------------------------------\n";
	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1;
		out(AUD[i]);
	}
	cout << "\n-------------------------------------------------------------------------------\n";
	check_and_out(AUD, n, check);

	system("pause");
}