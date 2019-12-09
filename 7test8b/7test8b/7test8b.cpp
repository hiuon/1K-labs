#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

struct tree
{
	int data;
	tree* right;
	tree* left;
};

void delete_l(tree*& top)
{
	if (top->right || top->left)
	{
		if (top->right)
			delete_l(top->right);
		if (top->left)
			delete_l(top->left);
	}
	else
	{
		delete top;
		top = NULL;
	}

}

void print_tree_level(tree* top, int level)
{
	if (top)
	{
		print_tree_level(top->left, level + 1);
		
		for (int i = 0; i < level; i++)
		{
			cout << "    ";
		}
		cout << top->data << '\n';
		print_tree_level(top->right, level + 1);
	}

}

tree* search(tree* top, int d)
{
	tree* pv = top, * ppv = top;
	while (pv)
	{
		ppv = pv;
		if (d > pv->data)
		{
			pv = pv->left;
		}
		else
		{
			pv = pv->right;
		}
	}
	return ppv;

}

void add(tree*& top, int d)
{
	if (!top)
	{
		top = new tree;
		top->data = d;
		top->left = top->right = NULL;
	}
	else
	{
		tree* ppv, * pnew = new tree;
		pnew->data = d;
		pnew->left = pnew->right = NULL;
		ppv = search(top, d);
		if (d > ppv->data)
		{
			ppv->left = pnew;
		}
		else
		{
			ppv->right = pnew;
		}
	}
}



int main()
{
	srand((unsigned)time(0));
	int n;
	cout << "Vvedite chislo elementov: "; cin >> n;
	tree* top = NULL;

	int* B = new int[n];
	cout << "B: ";
	for (int i = 0; i < n; i++)
	{
		B[i] = rand() % 100;
		cout << " " << B[i];
		add(top, B[i]);
	}
	cout << "\nDerevo: \n";
	print_tree_level(top, 0);

	delete_l(top);
	cout << "\nDerevo: \n";
	print_tree_level(top, 0);
}