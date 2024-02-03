#include "tree.cpp"
#include <iostream>

using namespace std;

int main() {
	TreeNode<int>* root = new TreeNode<int>(0);
	TreeNode<int>* one = new TreeNode<int>(1);
	TreeNode<int>* two = new TreeNode<int>(2);
	TreeNode<int>* tree = new TreeNode<int>(3);
	root->addChild(one);
	one->addChild(two);
	two->addChild(tree);
	cout << root->height();
}
