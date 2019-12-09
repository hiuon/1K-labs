#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	char str[] = "0123456789ABCDEF";
	for (int i = 1; i <= 1000000; i++)
	{
		bool palindrom10 = false;
		bool palindrom16 = false;
		bool palindrom16_ = false;
		char number10[10] = "";
		char number16[10] = "";
		char number16_[10] = "";

		int number = i;
		for (int j = 0; j < 10; j++)
		{
			if (number % 16 == 0)
			{
				number16_[j] = '0';
			}
			if (number % 16 == 1)
			{
				number16_[j] = '1';
			}
			if (number % 16 == 2)
			{
				number16_[j] = '2';
			}
			if (number % 16 == 3)
			{
				number16_[j] = '3';
			}
			if (number % 16 == 4)
			{
				number16_[j] = '4';
			}
			if (number % 16 == 5)
			{
				number16_[j] = '5';
			}
			if (number % 16 == 6)
			{
				number16_[j] = '6';
			}
			if (number % 16 == 7)
			{
				number16_[j] = '7';
			}
			if (number % 16 == 8)
			{
				number16_[j] = '8';
			}
			if (number % 16 == 9)
			{
				number16_[j] = '9';
			}
			if (number % 16 == 10)
			{
				number16_[j] = 'a';
			}
			if (number % 16 == 11)
			{
				number16_[j] = 'b';
			}
			if (number % 16 == 12)
			{
				number16_[j] = 'c';
			}
			if (number % 16 == 13)
			{
				number16_[j] = 'd';
			}
			if (number % 16 == 14)
			{
				number16_[j] = 'e';
			}
			if (number % 16 == 15)
			{
				number16_[j] = 'f';
			}
			if (number != 0)
			{
				number /= 16;
			}
			else
			{
				number16_[j] = '\0';
				break;
			}
		}

		_itoa_s(i, number10, 10);
		//_itoa_s(i, number16, 16);

		for (int j = 0; j < strlen(number10); j++)
		{
			if (number10[j] == number10[strlen(number10) - j - 1])
			{
				palindrom10 = true;
			}
			else
			{
				palindrom10 = false;
				break;
			}
		}

		/*
		for (int j = 0; j < strlen(number16); j++)
		{
			if (number16[j] == number16[strlen(number16) - j - 1])
			{
				palindrom16 = true;
			}
			else
			{
				palindrom16 = false;
				break;
			}
		}
		*/

		for (int j = 0; j < strlen(number16_); j++)
		{
			if (number16_[j] == number16_[strlen(number16_) - j - 1])
			{
				palindrom16 = true;
			}
			else
			{
				palindrom16 = false;
				break;
			}
		}
		if (palindrom10 == true && palindrom16 == true )
		{
			cout << setw(8) << number10 << setw(8) << number16_ << "\n";
		}
	}

	system("pause");
}