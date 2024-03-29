#include <iostream>

using namespace std;

int is_safe(int rows[8], int x, int y)
{
	int i;
	if (y == 0)
	{
		return 1;
	}
	for (i = 0; i < y; ++i)
	{
		if (rows[i] == x || rows[i] == x + y - i || rows[i] == x - y + i)
		{
			return 0;
		}
	}
	return 1;
}

void out(int rows[8], int &s, int sol)
{
	int x, y;
	s++;
	cout << "\nSolution #" << s << ":\n---------------------------------\n";
	for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 8; x++)
		{
			if (x == rows[y])
			{
				cout << "| Q ";
			}
			else
			{
				cout << "|   ";
			}
		}
		cout << "|\n---------------------------------\n";
	}	
}

void eight_queens_helper(int rows[8], int y, int sol, int &count)
{
	int x;
	if (count < sol)
	{
		for (x = 0; x < 8; x++) {
			if (is_safe(rows, x, y))
			{

				rows[y] = x;
				if (y == 7)
				{
					out(rows, count, sol);
				}
				else
				{
					eight_queens_helper(rows, y + 1, sol, count);
				}

			}
		}
	}
}


int main()
{
	int sol; 
	while (true)
	{
		cout << "Enter m: "; 
		cin >> sol;
		if (sol > 0)
		{
			break;
		}
		cout << "Try again.\n";
	}
	int count = 0;
	int rows[8];
	for (int i = 0; i < 8; i++)
	{
		rows[i] = 0;
	}
	eight_queens_helper(rows, 0, sol, count);
	cout << '\n';
	system("pause");
}