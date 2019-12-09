#pragma once
#include <iostream>

template <typename T>
struct TREE
{
	T data;
	TREE* right;
	TREE* left;
};

template <typename T>
class tree
{
	TREE<T>* top;
public:
	tree()
	{
		top = nullptr;
	}

	tree(T* mas, int size_m)
	{
		for (int i = 0; i < size_m; ++i)
		{
			add(top, *(mas + i));
		}
	}

	tree(tree<T>& obj)
	{
	
		copy_tree(obj.top, top);
	}

	~tree()
	{
		del(top);
	}

	void add(TREE<T>*& top, T d)
	{
		if (!top)
		{
			top = new TREE<T>;
			top->data = d;
			top->left = top->right = nullptr;
		}
		else
		{
			TREE<T>* ppv;
			TREE<T>* pnew = new TREE<T>;
			pnew->data = d;
			pnew->left = nullptr;
			pnew->right = nullptr;
			ppv = search(top, d);
			if (d < ppv->data)
			{
				ppv->left = pnew;
			}
			else
			{
				ppv->right = pnew;
			}
		}
	}

	TREE<T>* search(TREE<T>* t, T d)
	{
		TREE<T>* pv = t, * ppv = t;
		while (pv)
		{
			ppv = pv;
			if (d < pv->data)
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

	TREE<T>*& get_top()
	{
		return top;
	}

	TREE<T>*& search_e(TREE<T>*& t, int d)
	{
		TREE<T>* pv = t;
		while (pv)
		{
			if (d == pv->data)
			{
				break;
			}
			else if (d > pv->data)
			{
				pv = pv->right;
			}
			else
			{
				pv = pv->left;
			}
		}
		return pv;
	}

	void copy_tree(TREE<T>* top1, TREE<T>*& top2)
	{
		if (top1)
		{
			add(top2, top1->data);
			copy_tree(top1->left, top2);
			copy_tree(top1->right, top2);
		}
	}

	void del(TREE<T>*& t)
	{
		if (t)
		{
			del(t->left);
			del(t->right);
			delete t;
			t = nullptr;
		}
	}

	void out()
	{
		print_tree_level(top, 0);
	}

	void print_tree_level(TREE<T>* top1, int level)
	{
		if (top1)
		{
			print_tree_level(top1->left, level + 1);
			for (int i = 0; i < level; i++)
			{
				std::cout << "    ";
			}
			std::cout << top1->data << '\n';
			print_tree_level(top1->right, level + 1);
		}
	}

	void delete_all_l(TREE<T>*& top)
	{
		if (top->right || top->left)
		{
			if (top->right)
				delete_all_l(top->right);
			if (top->left)
				delete_all_l(top->left);
		}
		else
		{
			delete top;
			top = nullptr;
		}
	}	

	void delete_l(T d)
	{
		TREE<T>* pv = top;
		TREE<T>* ppv = top;
		bool k;
		while (pv)
		{
			if (d == pv->data)
			{
				if (pv->left == nullptr && pv->right == nullptr)
				{
					delete pv;
					if (k)
					{
						ppv->right = nullptr;
					}
					else
					{
						ppv->left = nullptr;
					}
					break;
				}	
			}
			if (d >= pv->data)
			{
				ppv = pv;
				pv = pv->right;
				k = true;
			}
			else
			{
				ppv = pv;
				pv = pv->left;
				k = false;
			}
		}
	}
};

template <typename T>
TREE<T>* search_el(tree<T>& obj, T d)
{
	return obj.search_e(obj.get_top(), d);
}

template <typename T>
void del_all_list(tree<T>& obj)
{
	obj.delete_all_l(obj.get_top());
}

