#include "VObj.h"
#include <fstream>

int main()
{
	VO ab;
	ifstream in("hardware.txt");
	ab.read(in);
	ab.print();
}