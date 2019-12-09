#include <iostream>
#include <stdlib.h>

using namespace std;

char* past(char * s, char * s1, int n)
{
	int newSize = strlen(s) + strlen(s1);
	char* newS = new char[newSize];
	int i = 0;

	for (i; i < n; i++)
	{
		newS[i] = s[i];
	}

	int j = 0;
	for (j; j < strlen(s1); j++, i++)
	{
		newS[i] = s1[j];
	}
	i--;
	j--;

	for (i; i < newSize + j; i++)
	{
		newS[i + 1] = s[i - j];
	}

	for (i = 0; i < newSize + j + 1; i++)
	{
		s[i] = newS[i];
	}

	return s;
}


int main()
{
	char str[1000];
	char str1[100];
	int vstavka;
	char symbolsX[] = {'.', ',', ';', '?', '!', '"', ' ', '\0'};
	cout << "Vvedite stroku: ";
	cin.getline(str, 1000);
	cout << "Vvedite stroku vsavki: ";
	cin.getline(str1, 100);
	cout << "Posistiya vstavki: ";
	cin >> vstavka;
	/*
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		if (i >= 1 && str[i] == 40 )
		{
			int check = 0;
			for (int j = 0; j < strlen(symbolsX); j++)
			{
				if (str[i - 1] == symbolsX[j])
				{
					check++;
				}
			}
			if (!check)
			{
				past(str, str1, i);
				i++;
			}
		}
		if (i < (strlen(str) - 1) && str[i] == 41) 
		{
			int check = 0;
			for (int j = 0; j < strlen(symbolsX); j++)
			{
				if (str[i + 1] == symbolsX[j])
				{
					check++;
				}
			}
			if (!check)
			{
				past(str, str1, i + 1);
				i++;
			}
		}
	}
	*/
	past(str, str1, vstavka);
	cout << "Otredatirovanaya stroka: " << str << endl;
	system("pause");
}