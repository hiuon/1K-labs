#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	cout << "Vvedite stroku: ";
	char str1[1000];
	int err;
	char str2[1000];
	cin.getline(str1, 999);
	err = _strlwr_s(str1, 999);
	int start = 0;
	int start2 = 0;
	int finish = 0;
	bool alpha = true;
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] == ' ' ||
			str1[i] == ',' ||
			str1[i] == '.' ||
			str1[i] == ':' ||
			str1[i] == ';' ||
			str1[i] == '!' ||
			str1[i] == '?' ||
			str1[i] == '-' ||
			str1[i] == '(' ||
			str1[i] == ')')
		{
			start += 1;
		}
		else
		{
			for (int j = i; j < strlen(str1); j++)
			{
				if ((str1[j + 1] == ' ' ||
					str1[j + 1] == ',' ||
					str1[j + 1] == '.' ||
					str1[j + 1] == ':' ||
					str1[j + 1] == ';' ||
					str1[j + 1] == '!' ||
					str1[j + 1] == '?' ||
					str1[j + 1] == '-' ||
					str1[j + 1] == '(' ||
					str1[j + 1] == ')' ||
					str1[j + 1] == '\0'))
				{
					finish = j + 1;
					break;
				}
				else if (str1[j] > str1[j + 1])
				{
					alpha = false;
				}
			}
			if (alpha == true)
			{
				for (start2; start < finish; start2++, start++)
				{
					str2[start2] = str1[start];
				}
				str2[start2] = ' ';
				str2[++start2] = '\0';
				start = finish;
				i = finish;
			}
			else
			{
				alpha = true;
				start = finish + 1;
				i = finish;
				str2[start2] = '\0';
			}
		}
	}
	cout << "Slova po usloviu: " << str2 << "\n";
	system("pause");
}
/*
	int start = 0;
	int finish;
	bool alf = true;
	int finish2 = 0;
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] == ' ' ||
			str1[i] == ',' ||
			str1[i] == '.' ||
			str1[i] == ':' ||
			str1[i] == ';' ||
			str1[i] == '!' ||
			str1[i] == '?' ||
			str1[i] == '-' ||
			str1[i] == '(' ||
			str1[i] == ')')
		{
			start = i + 1;
		}
		else
		{
			for (int j = i; j <= strlen(str1); j++)
			{
				if ((str1[j] == ' ' ||
					str1[j] == ',' ||
					str1[j] == '.' ||
					str1[j] == ':' ||
					str1[j] == ';' ||
					str1[j] == '!' ||
					str1[j] == '?' ||
					str1[j] == '-' ||
					str1[j] == '(' ||
					str1[j] == ')' ||
					str1[i] == '\0'))
				{
					i = j;
					finish = j;
					break;
				}
				else
				{
					if (str1[j + 1] == ' ' ||
						str1[j + 1] == ',' ||
						str1[j + 1] == '.' ||
						str1[j + 1] == ':' ||
						str1[j + 1] == ';' ||
						str1[j + 1] == '!' ||
						str1[j + 1] == '?' ||
						str1[j + 1] == '-' ||
						str1[j + 1] == '(' ||
						str1[j + 1] == ')' ||
						str1[j + 1] == '\0')
					{

					}
					else if (str1[j] > str1[j + 1])
					{
						alf = false;
					}
				}
			}
			if (alf == true)
			{
				int k;
				for (k = finish2; start < finish; k++)
				{
					str2[k] = str1[start++];
				}
				start = finish2 = k + 1;
				str2[finish2 - 1] = ' ';
				str2[finish2] = '\0';
			}
		}
		alf = true;
	}
	*/