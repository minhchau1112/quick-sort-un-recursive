#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* top;
};

void Init(Stack& s) {
	s.top = NULL;
}

bool isEmpty(Stack s) {
	if (s.top == NULL)return true;
	return false;
}

void Push(Stack& s, int data) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "Stack Overfolow" << endl;
		return;
	}
	p->data = data;
	p->next = s.top;
	s.top = p;
}

void Pop(Stack& s) {
	Node* p;
	if (s.top == NULL)
	{
		cout << "Stack Underflow" << endl;
		return;
	}
	else
	{
		p = s.top;
		s.top = s.top->next;
		delete[] p;
	}
}

void QuickSortUnRecursive(int* a, int l, int r) {
	Stack s_left;
	Init(s_left);
	Stack s_right;
	Init(s_right);
	Push(s_left, l);
	Push(s_right, r);
	while (isEmpty(s_left)==false) {
		l = s_left.top->data; Pop(s_left);
		r = s_right.top->data; Pop(s_right);
		int pivot = a[(l + r) / 2];
		int i = l, j = r;
		while (i <= j) {
			while (a[i] < pivot)i++;
			while (a[j] > pivot)j--;
			if (i <= j) {
				swap(a[i], a[j]);
				i++; j--;
			}
		}
		if (j > l) {
			Push(s_left, l);
			Push(s_right, j);
		}
		if (i < r) {
			Push(s_left, i);
			Push(s_right, r);
		}
	}
}

int main() {
	int* a;
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	QuickSortUnRecursive(a, 0, n - 1);
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	delete[] a;
	return 0;
}