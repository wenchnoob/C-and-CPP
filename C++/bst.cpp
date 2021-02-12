#include <iostream>
#include <string>

using namespace std;

template <class T>
class TreeNode {
	private:
		T val;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode(T val, TreeNode<T> *left = NULL, TreeNode<T> *right = NULL) {
			this->val = val;
			this->left = left;
			this->right = right;
		}
		
		T getVal() {
			return this->val;
		}
		
		TreeNode<T>* getLeft() {
			return this->left;
		}
		
		TreeNode<T>* getRight() {
			return this->right;
		}
		
		void setLeft(TreeNode<T> *left) {
			this->left = left;
		}
		
		void setRight(TreeNode<T> *right) {
			this->right = right;
		}
		
		void print() {
			cout << this->val << endl;
		}
};

template <class U>
class BinaryTree {
	private:
		TreeNode<U> *root;
		
	public:
		BinaryTree(TreeNode<U> *root = NULL) {
			this->root = root;
		}
		
		void insert(U val, TreeNode<U> *from = NULL) {
			if (root == NULL) {
				this->root = new TreeNode<U>(val);
				return;
			}
			
			if (from == NULL) {
				this->insert(val, this->root);
			} else {
				if (val > from->getVal()) {
					if (from->getRight() != NULL) {
						insert(val, from->getRight());
					} else {
						from->setRight(new TreeNode<U>(val));
						cout << val << " Inserted to the right of " << from->getVal() << endl;
					}
				} else {
					if (from->getLeft() != NULL) {
						insert(val, from->getLeft());
					} else {
						from->setLeft(new TreeNode<U>(val));
						cout << val << " Inserted to the left of " << from->getVal() << endl;
					}
				}
			}
		}
		
		void printRoot() {
			cout << this->root->getVal() << endl;
		}
		
		void print() {
			printTreeFromNode(this->root);
			cout << endl;
		}
		
		
		void printTreeFromNode(TreeNode<U> *node) {
			if (node->getLeft() != NULL) printTreeFromNode(node->getLeft());
			cout << node->getVal() << " ";
			if (node->getRight() != NULL) printTreeFromNode(node->getRight());
		}

};

int main() {
	BinaryTree<int> myTree;
	myTree.insert(12);
	myTree.insert(11);
	myTree.insert(2);
	myTree.insert(15);
	myTree.insert(123);
	
	myTree.printRoot();
	myTree.print();
}
