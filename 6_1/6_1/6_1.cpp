#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream in("in.txt", ios::in);
	fstream out("out.txt", ios::out);
	char str[100];
	while (!in.eof())
	{
		in.getline(str, 100, ' ');
		if (str[0] == 'K' || str[0] == 'S')
		{
			in.getline(str, 100, ' ');
			in.getline(str, 100, '\n');
			out << str << '\n';
		}
		else
		{
			in.getline(str, 100, '\n');
		}
	}
}