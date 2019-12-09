#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	char str[1000];
	cout << "Vvedite stroku: ";
	cin.getline(str, 999);
	int counter_in = 0;
	int	counter_out = 0;
	for (int i = 0, k = 0; i < strlen(str); i++)
	{
		if (str[i] == '(')
		{
			for (int j = i + 1; j < strlen(str); j++)
			{
				if (j == 2000000)
				{
					break;
				}
				if (str[j] == ')')
				{
					int j2 = j;
					int h = 1;
					for (int j1 = j; j1 >= i; j1--)
					{
						if (str[j1] == '(')
						{
							for (int k = j1; k <= j2; k++)
							{
								str[k] = str[j2 + h];
								h++;
							}
							for (int k = j2 + 1; k < strlen(str); k++)
							{
								str[k] = str[h + j2];
								h++;
							}
							i = 0;
							j = 2000000;
							h = 1;
							break;
						}
					}
				}
			}
		}
	}
	for (int i = 0, k = 0; i < strlen(str); i++)
	{
		if (str[i] == '(')
		{
			str[i+1] = '\0';
			break;
		}
	}
	
	/*for (int i = 0, k = 0; i < strlen(str); i++)
	{
		if (str[i] == ')')
		{
			for (k = 0; k <= strlen(str); k++)
			{
				str[k] = str[i + k + 1];
			}	
			i = -1;
		}
	}
	*/
	cout << "Stroka bez skobok: "<< str << "\n";
	system("pause");
}