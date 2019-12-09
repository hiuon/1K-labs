#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>

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
	
	void set_info();
	void print_info();
	~Hardware() {};
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
	void set_info();
	void print_info();
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
	void set_info();
	void print_info();
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
	void set_info();
	void print_info();
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
	void set_info();
	void print_info();
	~GPU() {};
};