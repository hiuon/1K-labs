#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class Hardware
{
protected:
	int price, reliability;
	string prod;
public:
	Hardware()
	{
		price = 0;
		reliability = 0;
		prod = "";
	};
	Hardware(int pr, int re, string str)
	{
		price = pr;
		reliability = re;
		prod = str;
	}
	virtual void write(ofstream& out, Hardware* obj)
	{
		out << obj->price << ' ' << obj->reliability << ' ' << obj->prod << '\n';
	}
	virtual bool check(Hardware* obj)
	{
		if (price == obj->price && reliability == obj->reliability && prod == obj->prod)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual void set_info();
	virtual void set_info(ifstream& in)
	{
		in >> price >> reliability >> prod;
	}
	virtual void print_info();
	virtual int type()
	{
		return -1;
	}
	virtual Hardware* Clone()
	{
		return new Hardware(price, reliability, prod);
	};
	virtual ~Hardware() {};
};

class Memory : public Hardware
{
protected:
	int size;
	int speed;
public:
	Memory()
	{
		size = 0; speed = 0;
	}
	Memory(int si, int sp, int pr, int re, string str)
	{
		price = pr;
		reliability = re;
		prod = str;
		size = si;
		speed = sp;
	}
	void write(ofstream& out, Hardware* obj)
	{
		Memory* temp = (Memory*)obj;
		out << temp->price << ' ' << temp->reliability << ' ' << temp->prod << ' ' << size << ' ' << speed << '\n';
	}
	void set_info(ifstream& in)
	{
		in >> price >> reliability >> prod >> size >> speed;
	}
	bool check(Hardware* obj)
	{
		Memory* temp = (Memory*)obj;
		if (price == temp->price && reliability == temp->reliability && prod == temp->prod && speed == temp->speed && size == temp->size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int type()
	{
		return 0;
	}
	void set_info();
	void print_info();
	~Memory() {};
};

class SSD : public Memory
{
protected:
	int Level_Cell;
public:
	SSD()
	{
		Level_Cell = 0;
	}
	SSD(int lc, int si, int sp, int pr, int re, string str)
	{
		speed = sp;
		size = si;
		prod = str;
		reliability = re;
		price = pr;
		Level_Cell = lc;
	}
	void set_info();
	void print_info();
	void write(ofstream& out, Hardware* obj)
	{
		SSD* temp = (SSD*)obj;
		out << temp->price << ' ' << temp->reliability << ' ' << temp->prod << ' ' << size << ' ' << speed << ' ' << Level_Cell << '\n';
	}
	void set_info(ifstream& in)
	{
		in >> price >> reliability >> prod >> size >> speed >> Level_Cell;
	}
	bool check(Hardware* obj)
	{
		SSD* temp = (SSD*)obj;
		if (price == temp->price && reliability == temp->reliability && prod == temp->prod && speed == temp->speed && size == temp->size && Level_Cell == temp->Level_Cell)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual Hardware* Clone()
	{
		return new SSD(Level_Cell, size, speed, price, reliability, prod);
	}
	int type()
	{
		return 1;
	}
	~SSD() {};
};

class HDD : public Memory
{
protected:
	int spindle_speed;
public:
	HDD()
	{
		spindle_speed = 0;
	}
	HDD(int ss, int si, int sp, int pr, int re, string str)
	{
		speed = sp;
		size = si;
		prod = str;
		reliability = re;
		price = pr;
		spindle_speed = ss;
	}
	void set_info();
	void print_info();
	void set_info(ifstream& in)
	{
		in >> price >> reliability >> prod >> size >> speed >> spindle_speed;
	}
	void write(ofstream& out, Hardware* obj)
	{
		HDD* temp = (HDD*)obj;
		out << temp->price << ' ' << temp->reliability << ' ' << temp->prod << ' ' << size << ' ' << speed << ' ' << spindle_speed << '\n';
	}
	bool check(Hardware* obj)
	{
		HDD* temp = (HDD*)obj;
		if (price == temp->price && reliability == temp->reliability && prod == temp->prod && speed == temp->speed && size == temp->size && spindle_speed == temp->spindle_speed)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual Hardware* Clone()
	{
		return new HDD(spindle_speed, size, speed, price, reliability, prod);
	}
	int type()
	{
		return 2;
	}
	~HDD() {};
};

class CPU : public Hardware
{
protected:
	int core;
	int freq;
public:
	CPU()
	{
		core = 0; freq = 0;
	}
	CPU(int c, int f, int pr, int re, string str)
	{
		prod = str;
		reliability = re;
		price = pr;
		core = c;
		freq = f;
	}
	void set_info();
	void print_info();
	void set_info(ifstream& in)
	{
		in >> price >> reliability >> prod >> core >> freq;
	}
	void write(ofstream& out, Hardware* obj)
	{
		CPU* temp = (CPU*)obj;
		out << temp->price << ' ' << temp->reliability << ' ' << temp->prod << ' ' << core << ' ' << freq << '\n';
	}
	bool check(Hardware* obj)
	{
		CPU* temp = (CPU*)obj;
		if (price == temp->price && reliability == temp->reliability && prod == temp->prod && core == temp->core && freq == temp->freq)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual Hardware* Clone()
	{
		return new CPU(core, freq, price, reliability, prod);
	}
	int type()
	{
		return 4;
	}
	~CPU() {};
};

class GPU : public Hardware
{
	int mem_size;
	int freq;
public:
	GPU()
	{
		mem_size = 0; freq = 0;
	}
	GPU(int m, int f, int pr, int re, string str)
	{
		prod = str;
		reliability = re;
		price = pr;
		mem_size = m;
		freq = f;
	}
	void set_info();
	void print_info();
	void set_info(ifstream& in)
	{
		in >> price >> reliability >> prod >> mem_size >> freq;
	}
	void write(ofstream& out, Hardware* obj)
	{
		GPU* temp = (GPU*)obj;
		out << temp->price << ' ' << temp->reliability << ' ' << temp->prod << ' ' << mem_size << ' ' << freq << '\n';
	}
	bool check(Hardware* obj)
	{
		GPU* temp = (GPU*)obj;
		if (price == temp->price && reliability == temp->reliability && prod == temp->prod && mem_size == temp->mem_size && freq == temp->freq)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual Hardware* Clone()
	{
		return new GPU(mem_size, freq, price, reliability, prod);
	}
	int type()
	{
		return 3;
	}
	~GPU() {};
};
