#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void check()
{
	string str = "0123456789ABCDEF";
	for (int i = 1; i <= 1000000; i++)
	{
		bool palindrom10 = false;
		bool palindrom16 = false;
		string number10;
		string number16;

		int number = i;
		for (int j = 0; j < 10; j++)
		{
			number16.append(str, number % 16, 1);
			number /= 16;
			if (!number)
			{
				break;
			}
		}
		number = i;
		for (int j = 0; j < 10; j++)
		{
			number10.append(str, number % 10, 1);
			number /= 10;
			if (!number)
			{
				break;
			}
		}

		for (int k = 0; k <= number16.length() / 2; k++)
		{
			if (number16[k] == number16[number16.length() - k - 1])
			{
				palindrom16 = true;
				swap(number16[k], number16[number16.length() - k - 1]);
			}
			else
			{
				palindrom16 = false;
				break;
			}
		}

		for (int k = 0; k <= number10.length() / 2; k++)
		{
			if (number10[k] == number10[number10.length() - k - 1])
			{
				palindrom10 = true;
				swap(number10[k], number10[number10.length() - k - 1]);
			}
			else
			{
				palindrom10 = false;
				break;
			}
		}
			

		if (palindrom10 == true && palindrom16 == true)
		{
			cout << setw(8) << number10 << setw(8) << number16 << "\n";
		}
	}
}

int main()
{
	check();
	system("pause");
}