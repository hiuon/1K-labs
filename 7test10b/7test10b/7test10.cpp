#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

struct list
{
	int number;
	list* next;
};

struct graf
{
	int numberVertex;
	list* listVertex;
	graf* next;
};

