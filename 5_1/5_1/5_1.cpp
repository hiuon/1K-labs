#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool make_words(char* words, char* word)
{
	if (strlen(words) == 0)
	{
		return false;
	}
	int g = 0;
	for (int i = 0; i < strlen(words); ++i)
	{
		if (words[i] == ' ')
		{
			g = i;
			for (int j = 0; j < i; ++j)
			{
				word[j] = words[j];
			}
			break;
		}
		if (i == strlen(words) - 1)
		{
			for (int j = 0; j < strlen(words); ++j)
			{
				word[j] = words[j];
			}
			words[0] = '\0';
			return true;
		}
	}
	int k = strlen(words);
	for (int i = g, l = 0; i < k; ++i, ++l)
	{
		words[l] = words[i + 1];
	}
	return true;
}

int main()
{
	fstream in("out.txt", ios::in);
	fstream out("in.txt", ios::out);
	char words[1000] = "";
	char word[30] = "";
	while (!in.eof())
	{
		bool check = true;
		in.getline(words, 999);
		while (make_words(words, word))
		{
			for (int i = 0; i < strlen(word); ++i)
			{
				if (word[i] == '*' || word[i] == '/')
				{
					check = false;
					break;
				}
			}
			if (check)
			{
				out << word;
				if (words[0] == '\0')
				{
					out << '\n';
				}
				else
				{
					out << ' ';
				}
			}
		}
	}
	in.close();
	out.close();
}