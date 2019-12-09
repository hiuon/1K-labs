#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

void createB(ofstream &f, int n)
{
	for (int i = 0; i < n; i++)
	{
		int v = rand() % 300;
		f.write(reinterpret_cast <char*>(&v), sizeof(int));
	}
	
}
void create(fstream &f, int n)
{
	for (int i = 0; i < n; i++)
	{
		int v = rand() % 300;
		f << v << endl;
	}
}

void create_from(fstream &f, fstream &g, int n)
{

	int k;
	while (f >> k)
	{
		if (k % 2 == 0)
		{
			g << k << endl;
		}
	}
	f.clear();
	f.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		int k;
		f >> k;
		if (k % 2 == 1)
		{
			g << k << endl;
		}
	}
}

void create_fromB(ifstream &f, ofstream &g, int n)
{
	int k;
	for (int i = 0; i < n; i++)
	{
		f.read((char*)&k, sizeof(k));
		if (k % 2 == 0)
		{
			g.write(reinterpret_cast <char*>(&k), sizeof(int));
		}
		
	}
	f.clear();
	f.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		f.read((char*)&k, sizeof(k));
		if (k % 2 == 1)
		{
			g.write(reinterpret_cast <char*>(&k), sizeof(int));
		}
	}
}

void out_bin(ifstream &f)
{
	int k;
	f.clear();
	f.seekg(0, ios::beg);
	while (f.read((char*)(&k), sizeof(k)))
	{
		cout << setw(4) << k;
	}
	cout << endl;
}

int main()
{
	cout << "Vvedite kolichestvo chisel: ";
	int N; cin >> N;
	srand((unsigned)time(0));
	fstream F("fileF.txt");
	fstream G("fileG.txt");
	if (!F || !G)
	{
		cout << "Error!!!";
		return 1;
	}
	create(F, N);
	F.close();
	F.open("fileF.txt");
	create_from(F, G, N);
	G.close();
	/////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	ofstream FB("fileF.bin", ios::binary);
	ofstream GB("fileG.bin", ios::binary);
	createB(FB, N);
	FB.close();
	ifstream FB1("fileF.bin", ios::binary);
	create_fromB(FB1, GB, N);
	GB.close();
	out_bin(FB1);
	FB1.clear();
	FB1.close();
	FB1.open("fileG.bin", ios::binary);
	out_bin(FB1);
	FB.close();
	GB.close();
	system("pause");
}
