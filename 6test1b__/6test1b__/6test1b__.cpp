#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string find_word(string &buf, string razd, string str, int &fn, int &i)
{
	int st = fn;
	bool check = true;
	for (fn; fn <= str.length(); fn++)
	{
		for (int k = 0; k < razd.length(); k++)
		{
			if (str.at(fn) == razd.at(k))
			{
				check = false;
				if (!buf.empty())
				{
					i = fn;
					fn++;
					return buf;
				}
				break;
			}
		}
		if (check)
		{
			buf += str.at(fn);
		}
		check = true;
	}
}

void comp_write(string &New, string &buf)
{
	bool check = true;
	for (int i = 0; i < buf.length(); i++)
	{
		if (i + 1 >= buf.length())
		{
			break;
		}
		else if ((buf.at(i) > buf.at(i + 1)))
		{
			check = false;
		}
	}
	if (check)
	{
		New += buf;
		New += ' ';
	}
	buf.clear();
}

string check(string &str)
{
	string New;
	str += ' ';
	string razd = " .,:;!?-()";
	string buf;
	int st = 0;
	for (int i = 0; i < str.length(); i++)
	{
		find_word(buf, razd, str, st, i);
		comp_write(New, buf);
	}
	return New;
}

int main()
{
	cout << "Vvedite stroku: ";
	string str;
	getline(cin, str);
	cout << "Otredaktirovannaya stroka: " << check(str) << '\n';
	system("pause");
}
