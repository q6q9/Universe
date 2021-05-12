#include <iostream>
#include <windows.h>
using namespace std;

class A {
	friend A* tree(const string& s, A* a);
	friend void print_tree(A* a);
	friend void del_tree(A* a);
private:
	int count;
	string s;
	A* right = 0, * left = 0;

	
	A* c_plus(A* a) {
		cout << s <<000000000000000000000<< endl;
		if (a == 0) return a;
		++count++;
		 a->right = c_plus(right);
		 a->left = c_plus(left);s
		return a;
	}
	int aa() { return 34765; }

public:
	A(const string& s = "empty") :s(s), count(1) {}

	string get_s() {
		return s;
	}
	int get_c() {
		return count;
	}
	//увеличивает кол-во повторений всех значений веток данного дерева
	A* A::operator++(int) {
		cout<< aa();
		cout << 555;
		
		*this = this.c_plus(this);
		return this;
	}
};
//увеличивает кол-во повторений всех значений веток данного дерева

//сравнение 2 строк
int compare(string s1, string s2) {
	int a = s1.length() + 1, b = s2.length() + 1;
	char* text1 = new char[a];
	char* text2 = new char[b];

	for (size_t i = 0; i < a; i++) {
		text1[i] = s1[i];
	}
	for (size_t i = 0; i < b; i++) {
		text2[i] = s2[i];
	}
	int x = strcmp(text1, text2);
	free(text1);
	free(text2);
	return x;
}

void print_tree(A* a) {
	if (a != NULL) {
		print_tree(a->left);
		cout << a->count << " " << a->s << endl;
		print_tree(a->right);
	}
}

A* tree(const string& s, A* a) {

	if (!a) {
		a = new A();
		a->s = s;


	}
	else {

		int x = compare(s, a->get_s());
		if (!x) {
			a->count++;
		}
		else if (x > 0) {
			a->right = tree(s, a->right);
		}
		else {
			a->left = tree(s, a->left);
		}
	}
	return a;
}

void del_tree(A* a) {
	if (a) {
		del_tree(a->left);
		del_tree(a->right);
		free(a);
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	A* node = 0;
	int n;
	string s;
	cout << "Введите кол-во веток бинарного дерева:\n";
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> s;
		node = tree(s, node);
	}

	(*node)++;
	print_tree(node);
	del_tree(node);
	return 0;
}