#include <iostream>
using namespace std;
#include <stack>
class tree {
public:
	tree* left;
	tree* right; 

	float value; 

	tree(float value) {
		cout << "делаю узел со значением "<< value<< "\n";
		this->value = value;
		left = nullptr;
		right = nullptr; 
	}

	
};

int main() {

	setlocale(LC_ALL, "rus");
	
	cout << "enter number of nodes\n";
	int num;
	cin >> num;
	num--;
	cout << "enter value of root\n";
	int val;
	cin >> val;
	tree* root = new tree(val);
	tree* current = root;
	tree* next = root;
	
	int l, r;
	int ne;
	stack<tree*> nextTree; 

	for (size_t i = 0; i < num; i = i+2)
	{
		cout << "enter sons of " << current->value<<"\n";
		cin >> l >> r; 
		
		current->left = new tree(int(l));
		current->right = new tree(int(r));
		cout << "where to go next? " << l << " or " << r << "?\n";
		cin >> ne; 
		if (ne == l) { 
			nextTree.push(current->right);
			current = current->left; 
		}
		else if(ne == r) {
			nextTree.push(current->left);
			current = current->right;
		}
		else {
			if (!nextTree.empty()) {
				cout << "stack is not empty,so going up\n";
				current = nextTree.top();  nextTree.pop();
				cout << current->value;
			}
			else cout << "i am in root\n";
		}
	
	}
	current = root;
	stack<tree*> NextTree; 

	for (size_t i = 0; i <= num; i++)
	{
		cout << "i am at " << current->value << "\n";
		if (current->left != nullptr) {
			cout << "sons are " << current->left->value << " and " << current->right->value <<". Go to left son\n";
			NextTree.push(current->right);
			current = current->left;
		}
		else {
			cout << "no sons. going to right son of previous node\n";
			if (NextTree.empty()) {
				cout << "whole tree is shown. finised.\n";
				break;
			}
			current = NextTree.top();
			NextTree.pop();
		}
		
	}
	cout << "here";
	return 0; 

}