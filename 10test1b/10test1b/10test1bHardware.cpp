#include "10test1b.h"

void Hardware::set_info()
{
	cout << "Price: "; cin >> price;
	cout << "Reliability: "; cin >> reliability;
	cout << "Product Name: "; cin.get(); getline(cin, prod);
}

void Hardware::print_info()
{
	cout << "Price: "; cout << price << '\n';
	cout << "Reliability: "; cout << reliability << '\n';
	cout << "Product Name: "; cout << prod << '\n';
}

void Memory::print_info()
{
	Hardware::print_info();
	cout << "Size: "; cout << size << '\n';
	cout << "Speed: "; cout << speed << '\n';
}

void Memory::set_info()
{
	Hardware::set_info();
	cout << "Size: "; cin >> size;
	cout << "Speed: "; cin >> speed;
}

void SSD::set_info()
{
	Memory::set_info();
	cout << "Level cell: "; cin >> Level_Cell;
}

void SSD::print_info()
{
	Memory::print_info();
	cout << "Level cell: "; cout << Level_Cell << '\n';
}

void HDD::set_info()
{
	Memory::set_info();
	cout << "Spindle speed: "; cin >> spindle_speed;
}

void HDD::print_info()
{
	Memory::print_info();
	cout << "Spindle speed: "; cout << spindle_speed << '\n';
}

void CPU::set_info()
{
	Hardware::set_info();
	cout << "Number of cores: "; cin >> core;
	cout << "Frequency: "; cin >> freq;
}

void CPU::print_info()
{
	Hardware::print_info();
	cout << "Number of cores: "; cout << core << '\n';
	cout << "Frequency: "; cout << freq << '\n';
}

void GPU::set_info()
{
	Hardware::set_info();
	cout << "Memory size: "; cin >> mem_size;
	cout << "Frequency: "; cin >> freq;
}

void GPU::print_info()
{
	Hardware::print_info();
	cout << "Memory size: "; cout << mem_size << '\n';
	cout << "Frequency: "; cout << freq << '\n';
}