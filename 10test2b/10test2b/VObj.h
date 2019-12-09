#pragma once
#include "Hardware.h"
#include <vector>
#include <string>
#include <fstream>

class VO
{
	int s;
	Hardware** mas;
	
public:
	VO() 
	{
		s = 0; 
		mas = nullptr;
	}

	VO(const VO& obj)
	{
		s = obj.s;
		Hardware** temp = new Hardware*[s];
		for (int i = 0; i < s; ++i)
		{
			temp[i] = obj.mas[i]->Clone();
		}
		delete mas;
		mas = temp;
	}

	VO(VO&& obj) noexcept : s(obj.s), mas(obj.mas)
	{
		obj.s = 0;
		obj.mas = nullptr;
	}

	VO operator=(VO&& obj) noexcept
	{
		s = obj.s;
		mas = obj.mas;
		obj.s = 0;
		obj.mas = nullptr;
	}

	VO operator=(const VO& obj)
	{
		s = obj.s;
		Hardware** temp = new Hardware * [s];
		for (int i = 0; i < s; ++i)
		{
			temp[i] = obj.mas[i]->Clone();
		}
		delete mas;
		mas = temp;
	}
	
	void add()
	{
		cout << "Vvedite chislo elementov: ";
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cout << "Vvedite tip (1 - SSD, 2 - HDD, 3 - GPU, 4 - CPU): ";
			int t; cin >> t;
			switch (t)
			{
			case 1:
			{
				SSD* ssd1 = new SSD;
				ssd1->set_info();
				this->add(ssd1);
				continue;
			}
			case 2:
			{
				HDD* ssd1 = new HDD;
				ssd1->set_info();
				this->add(ssd1);
				continue;
			}
			case 3:
			{
				GPU* ssd1 = new GPU;
				ssd1->set_info();
				this->add(ssd1);
				continue;
			}
			case 4:
			{
				CPU* ssd1 = new CPU;
				ssd1->set_info();
				this->add(ssd1);
				continue;
			}
			}
		}
	}

	void add(Hardware* obj)
	{
		s = s + 1;
		Hardware** temp = new Hardware * [s];
		for (int i = 0; i < s - 1; ++i)
		{
			temp[i] = mas[i]->Clone();
		}
		temp[s - 1] = obj;
		delete mas;
		mas = temp;
	}

	void print()
	{
		cout << '\n' << "Massiv\n";
		for (int i = 0; i < s; ++i)
		{
			mas[i]->print_info();
			cout << '\n';
		}
	}

	void del()
	{
		cout << "Vvedite tip (1 - SSD, 2 - HDD, 3 - GPU, 4 - CPU): ";
		int t; cin >> t;
		switch (t)
		{
		case 1:
		{
			SSD* ssd1 = new SSD;
			ssd1->set_info();
			this->del(ssd1);
			break;
		}
		case 2:
		{
			HDD* ssd1 = new HDD;
			ssd1->set_info();
			this->del(ssd1);
			break;
		}
		case 3:
		{
			GPU* ssd1 = new GPU;
			ssd1->set_info();
			this->del(ssd1);
			break;
		}
		case 4:
		{
			CPU* ssd1 = new CPU;
			ssd1->set_info();
			this->del(ssd1);
			break;
		}
		}
	}

	void del(Hardware* obj)
	{
		for (int i = 0; i < s; i++)
		{
			if (mas[i]->type() == obj->type())
			{
				if (mas[i]->check(obj))
				{
					Hardware** temp = new Hardware * [s - 1];
					for (int j = 0; j < i; ++j)
					{
						temp[j] = mas[j]->Clone();
					}
					for (int j = i + 1; j < s; ++j)
					{
						temp[j - 1] = mas[j]->Clone();
					}
					s--;
					delete mas;
					mas = temp;
					break;
				}
			}
		}
	}

	void read(ifstream& in)
	{
		if (this->mas)
		{
			delete mas;
			mas = nullptr;
		}
		while (!in.eof())
		{ 
			int t; in >> t;
			if (in.eof())
			{
				break;
			}
			switch (t)
			{
			case 1:
			{
				SSD* ssd1 = new SSD;
				ssd1->set_info(in);
				this->add(ssd1);
				continue;
			}
			case 2:
			{
				HDD* ssd1 = new HDD;
				ssd1->set_info(in);
				this->add(ssd1);
				continue;
			}
			case 3:
			{
				GPU* ssd1 = new GPU;
				ssd1->set_info(in);
				this->add(ssd1);
				continue;
			}
			case 4:
			{
				CPU* ssd1 = new CPU;
				ssd1->set_info(in);
				this->add(ssd1);
				continue;
			}
			}
		}
	}

	void write(ofstream& out)
	{
		for (int i = 0; i < s; ++i)
		{
			int t = mas[i]->type();
			out << t << ' ';
			mas[i]->write(out, mas[i]);
		}
	}

	~VO() 
	{
		if (mas)
		{
			delete mas;
		}
	}
};
