#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_symbol(string sym)
{
	if (sym == "<" || sym == ">" || sym == "<=" || sym == ">=" || sym == "==" || sym == "!=" || sym == "&&" || sym == "||" || sym == "!" || sym == ")" || sym == "(")
	{
		return true;
	}
	return false;
}

short priority(string sym)
{
	if (sym == "(")
	{
		return 6;
	}

	if (sym == "!")
	{
		return 1;
	}

	if (sym == "<" || sym == ">" || sym == "<=" || sym == ">=")
	{
		return 2;
	}

	if (sym == "==" || sym == "!=")
	{
		return 3;
	}

	if (sym == "&&")
	{
		return 4;
	}

	if (sym == "||")
	{
		return 5;
	}
}

void pnotation(string& lv, stack<string>& pn, string& out)
{
	for (int i = 0; i < lv.size(); ++i)
	{
		string str;
		while (lv[i] != ' ')
		{
			str.push_back(lv[i]);
			i++;
			if (i == lv.size())
			{
				break;
			}
		}
		if (!is_symbol(str))
		{
			out += str;
			out += ' ';
		}
		else
		{
			if (str == "(")
			{
				pn.push(str);
			}
			else if (str == ")")
			{
				while (pn.top() != "(")
				{
					out += pn.top();
					out += ' ';
					pn.pop();
				}
				pn.pop();
			}
			else if (pn.empty())
			{
				pn.push(str);
			}
			else
			{
				if (priority(str) < priority(pn.top()))
				{
					pn.push(str);
				}
				else
				{
					while (!pn.empty() && (priority(str) > priority(pn.top())))
					{
						out += pn.top();
						out += ' ';
						pn.pop();
					}
					pn.push(str);
				}
			}
		}
	}
	while (!pn.empty())
	{
		out += pn.top();
		out += ' ';
		pn.pop();
	}
	out.pop_back();
}

void solution(string out, stack<string>& pn)
{
	bool answer;
	for (int i = 0; i < out.size(); ++i)
	{
		string str;
		while (out[i] != ' ')
		{
			str.push_back(out[i]);
			i++;
			if (i == out.size())
			{
				break;
			}
		}
		if (!is_symbol(str))
		{
			pn.push(str);
		}
		else
		{
			if (str == "!")
			{
				string res = pn.top();
				pn.pop();
				if (res == "t")
				{
					res = "f";
				}
				else if (res == "f")
				{
					res = "t";
				}
				else if (res != "0")
				{
					res = "f";
				}
				else
				{
					res = "t";
				}
				pn.push(res);
			}
			if (str == "<")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (atoi(res1.c_str()) < atoi(res.c_str()))
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
			if (str == "<=")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (atoi(res1.c_str()) <= atoi(res.c_str()))
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
			if (str == ">")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (atoi(res1.c_str()) > atoi(res.c_str()))
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
			if (str == ">=")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (atoi(res1.c_str()) >= atoi(res.c_str()))
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
			if (str == "==")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (atoi(res.c_str()) == atoi(res1.c_str()) && res == res1)
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
			if (str == "!=")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (atoi(res.c_str()) != atoi(res1.c_str()) && res != res1)
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
			if (str == "&&")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (res == "t" || res == "f")
				{
					if (res1 != "t" && res1 != "f")
					{
						if (res1 == "0")
						{
							res1.clear();
							res1 = "f";
						}
						else
						{
							res1.clear();
							res1 = "t";
						}
					}
				}
				if (res1 == "t" || res1 == "f")
				{
					if (res != "t" && res != "f")
					{
						if (res == "0")
						{
							res.clear();
							res = "f";
						}
						else
						{
							res.clear();
							res = "t";
						}
					}
				}
				if (res != "t" && res != "f")
				{
					if (res1 != "t" && res1 != "f")
					{
						if (res == "0")
						{
							res.clear();
							res = "f";
						}
						else
						{
							res.clear();
							res = "t";
						}

						if (res1 == "0")
						{
							res1.clear();
							res1 = "f";
						}
						else
						{
							res1.clear();
							res1 = "t";
						}
					}
				}
				if (res == "t" && res1 == "t")
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
			if (str == "||")
			{
				string res = pn.top(); pn.pop();
				string res1 = pn.top(); pn.pop();
				if (res == "t" || res1 == "t" || (atoi(res.c_str()) || atoi(res1.c_str())))
				{
					res = "t";
					pn.push(res);
				}
				else
				{
					pn.push("f");
				}
			}
		}

	}
	if (pn.top() == "t")
	{
		cout << "Answer: True\n";
	}
	else if (pn.top() == "f")
	{
		cout << "Answer: False\n";
	}
	else if (pn.top() != "0")
	{
		cout << "Answer: True\n";
	}
	else
	{
		cout << "Answer: False\n";
	}

	 
}

int main()
{
	stack<string> pn;
	string lv, out;
	cout << "Vvedite vyrajeniye[5 && ( 0 <= 3 ) || f]: ";
	getline(cin, lv);
	pnotation(lv, pn, out);
	cout << "Vyrajeniye v polskoy notatsii: " << out << '\n';
	solution(out, pn);
}

