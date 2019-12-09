#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool word_(char *, char *, int&);
void write_words(char [][30], char*, int&);
void change_str(char [][30], int);
bool word_r(char *, char *, int&);


int main()
{
	char str[1000];
	char word[100];
	char arr_word[100][30];
	int pos_word = 0;
	int pos = 0;
		
	cout << "Vvedite predlojenie: ";
	cin.getline(str, 999);

	while (word_(str, word, pos) || word_r(str, word, pos))
	{
		write_words(arr_word, word, pos_word);
	}

	change_str(arr_word, pos_word);
	cout << '\n';
	system("pause");
}

bool word_r(char * str, char * word, int& pos)
{
	bool check = false;
	char razd[] = " .,:;!?-()";
	if (str[pos] == '\0')
	{
		return false;
	}
	for (int i = 0; ; pos++, i++)
	{
		for (int j = 0; j < strlen(razd) + 1; j++)
		{
			if (str[pos] == razd[j])
			{
				word[i] = str[pos];
				check = true;
			}
		}
		if (!check)
		{
			word[i] = '\0';
			break;
		}
		check = false;
	}
	return true;
}

bool word_(char * str, char * word, int& pos)
{
	bool check = true;
	char razd[] = " .,:;!?-()";
	for (int i = 0; i < strlen(razd) + 1; i++)
	{
		if (str[pos] == razd[i])
		{
			return false;
		}
	}
	for (int i = 0; ; pos++, i++)
	{
		for (int j = 0; j < strlen(razd) + 1; j++)
		{
			if (str[pos] == razd[j])
			{
				check = false;
				break;
			}
		}
		word[i] = str[pos];
		if (!check)
		{
			word[i] = '\0';
			break;
		}
		
	}
	
	return true;
}

void write_words(char str[][30], char * word, int& pos)
{
	int i = 0;
	for (i; i < strlen(word); i++)
	{
		str[pos][i] = word[i];
	}
	str[pos][i] = '\0';
	pos++;
}

void change_str(char check[][30], int pos)
{
	bool del = false;
	int h = 0;
	for (int i = 0; i < pos; i += 2)
	{
		for (int j = i + 2; j < pos; j += 2)
		{
			if (strlen(check[i]) == strlen(check[j]))
			{
				for (int j1 = 0; j1 < strlen(check[i]); j1++)
				{
					if (check[i][j1] == check[j][j1])
					{
						del = true;
					}
					else
					{
						del = false;
						break;
					}
				}
				if (del)
				{
					h = 0;
					for (int k = j - 1; k < pos; k++ )
					{
						for (int j1 = 0; j1 < 30; j1++)
						{
							check[k + 1][j1] = check[k + 2][j1];
							if (check[k + 2][j1] == '\0')
							{
								break;
							}
						}
					}
					pos--;
					j--;
					h++;

				}
			}
		}
		i += h;
	}
	cout << "Otredaktirovannaya predlojenie: ";
	for (int j = 0; j < pos; j++)
	{
		cout << check[j];
	}
}
