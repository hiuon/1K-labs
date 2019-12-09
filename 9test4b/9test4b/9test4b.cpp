#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
	fstream in("9test4b.cpp", ios::in);
	fstream cc("9test4b.cpp", ios::in);
	fstream out("output.txt", ios::out);
	const set<string> keywords = { "alignas",
									"alignof",
									"and",
									"and_eq",
									"asm",
									"auto",
									"bitand",
									"bitor",
									"bool",
									"break",
									"case",
									"catch",
									"char",
									"char16_t",
									"char32_t",
									"class",
									"compl",
									"const",
									"constexpr",
									"const_cast",
									"continue",
									"decltype",
									"default",
									"delete",
									"do",
									"double",
									"dynamic_cast",
									"else",
									"enum",
									"explicit",
									"export",
									"extern",
									"false",
									"float",
									"for",
									"friend",
									"goto",
									"if",
									"inline",
									"int",
									"long",
									"mutable",
									"namespace",
									"new",
									"noexcept",
									"not",
									"not_eq",
									"nullptr",
									"operator",
									"or",
									"or_eq",
									"private",
									"protected",
									"public",
									"register",
									"reinterpret_cast",
									"return",
									"short",
									"signed",
									"sizeof",
									"static",
									"static_assert",
									"static_cast",
									"struct",
									"switch",
									"template",
									"this",
									"thread_local",
									"throw",
									"true",
									"try",
									"typedef",
									"typeid",
									"typename",
									"union",
									"unsigned",
									"using",
									"virtual",
									"void",
									"volatile",
									"wchar_t",
									"while",
									"xor",
									"xor_eq" };

	map<string, vector<unsigned>> counts;
	string word;
	char w, y;
	unsigned counter = 1;
	while (in >> word)
	{
		while (!cc.eof())
		{		
			cc.get(w);
			if (w == ' ' || w == '\n')
			{
				y = w;
				cc.get(w);
				if (w != ' ' && w != '\n')
				{
					break;
				}
				else
				{
					while (w == ' ' || w == '\n')
					{
						if (w == '\n')
						{
							counter++;
						}
						cc.get(w);
					}
				}
				break;
			
			}
		}
		if (keywords.count(word) != 0)
		{
			if (counts[word].size() == 0)
			{
				counts[word].push_back(0);
			}
			counts[word][0]++;
			if (counts[word][counts[word].size() - 1] != counter)
			{
				counts[word].push_back(counter);
			}
		}
		if (y == '\n')
		{
			counter++;
		}
	}
	for (const auto& wordCount : counts)
	{
		out << wordCount.first << ": " << wordCount.second[0] << ", v strokakh:";
		for (int i = 1; i < wordCount.second.size(); ++i)
		{
			out << " " << wordCount.second[i];
		}
		out << '\n';
	}
	in.close();
	cc.close();
	out.close();
}