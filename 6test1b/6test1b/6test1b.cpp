#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void editor_string(string &str)
{
	for (unsigned i = 0; i < str.length(); i++)
	{
		bool check = false;
		if (str[i] == '(')
		{
			for (unsigned j = i + 1; j < str.length(); j++)
			{
				if (check)
				{
					i = 0;
					break;
				}
				if (str[j] == ')')
				{
					for (unsigned j1 = j; ; j1--)
					{
						if (str[j1] == '(')
						{
							str.erase(j1, j - j1 + 1);
							check = true;
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0, k = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			str.erase(i + 1);
			break;
		}
	}
}

int main()
{
	string str;
	cout << "Vvedite stroku: ";
	getline(cin, str);
	editor_string(str);
	cout << "Stroka bez skobok: " << str << "\n";
	system("pause");
}