#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

bool word_(vector<char>&, vector<char>&, int&);
void write_words(vector<vector<char>>&, vector<char>&, int&);
void change_str(vector<vector<char>>&, int);
bool word_r(vector<char>&, vector<char>&, int&);


int main()
{
	vector<char> str;
	vector<char> word;
	vector<vector<char>> arr_word;
	int pos_word = 0;
	int pos = 0;
	cout << "Vvedite predlojenie: ";
	char temp[1000];
	cin.getline(temp, 1000);
 	for (int i = 0; i < strlen(temp); ++i)
	{
		str.push_back(temp[i]);
	}
	
	

	while (word_(str, word, pos) || word_r(str, word, pos))
	{
		write_words(arr_word, word, pos_word);
	}

	change_str(arr_word, pos_word);
	cout << '\n';
	system("pause");
}

bool word_r(vector<char>& str, vector<char>& word, int& pos)
{
	bool check = false;
	char razd1[] = " .,:;!?-()";
	vector<char> razd;
	for (int i = 0; i < strlen(razd1); ++i)
	{
		razd.push_back(razd1[i]);
	}
	if (str.size() == pos)
	{
		return false;
	}
	for (int i = 0; ; pos++, i++)
	{
		for (int j = 0; j < razd.size(); j++)
		{
			if (str[pos] == razd[j])
			{
				word.push_back(str[pos]);
				check = true;
			}
		}
		if (!check)
		{
			break;
		}
		check = false;
	}
	return true;
}

bool word_(vector<char>& str, vector<char>& word, int& pos)
{
	bool check = true;
	char razd1[] = " .,:;!?-()";
	vector<char> razd;
	for (int i = 0; i < strlen(razd1); ++i)
	{
		razd.push_back(razd1[i]);
	}
	for (int i = 0; i < razd.size(); i++)
	{
		if (str.size() == pos || str[pos] == razd[i])
		{
			return false;
		}
	}
	for (int i = 0; pos < str.size(); pos++, i++)
	{
		for (int j = 0; j < razd.size(); j++)
		{
			if (str[pos] == razd[j])
			{
				check = false;
				break;
			}
		}
		if (!check)
		{
			break;
		}
		else
		{
			word.push_back(str[pos]);
		}

	}

	return true;
}

void write_words(vector<vector<char>>& str, vector<char>& word, int& pos)
{
	int i = 0;
	vector<char> temp;
	for (i; i < word.size(); i++)
	{
		temp.push_back(word[i]);
	}
	str.push_back(temp);
	pos++;
	word.clear();
}

void change_str(vector<vector<char>>& check, int pos)
{
	bool del = false;
	int h = 0;
	for (int i = 0; i < check.size(); i += 2)
	{
		for (int j = i + 2; j < check.size(); j += 2)
		{
			if (check[i].size() == check[j].size())
			{
				for (int j1 = 0; j1 < check[i].size(); j1++)
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
					check[j].clear();
					pos--;
				}
			}
		}
	}
	cout << "Otredaktirovannaya predlojenie: ";
	for (int j = 0; j < check.size(); j++)
	{
			for (int k = 0; k < check[j].size(); ++k)
			{
				cout << check[j][k];
			}
	}
}
