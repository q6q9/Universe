#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;


struct node 
{
	int x, count;
	node* left, *right;
};



node* add_tree(node* a, int& y) 
{
	if (!a)
	{
		a = new node[sizeof(node)];
		a->x = y;
		a->count = 1;
		a->left = a->right = NULL;
	}
	else if (a->x == y)
		a->count++;
	else if (a->x < y)
		a->right = add_tree(a->right, y);
	else
		a->left = add_tree(a->left, y);
	//cout << "hi";
	return a;
}

void print(node* a)
{	
	if (!a)
		return;
	print(a->left);
	cout << a->count << " " << a->x << endl;
	print(a->right);
	//10 20 10 -7 5 21 20 -8 0 25 23
}
void free(node *a) {
	if (!a)
		return;
	free(a->left);
	delete[] a;

}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int j,x;
	node *root = NULL;
	cout << "Введите кол-во элементов:\n";
	cin >> j;
	for (size_t i = 0; i < j; i++)
	{
		cin >> x;
		root = add_tree(root, x);
	}
	cout << endl << endl;
	print(root);
	
}

