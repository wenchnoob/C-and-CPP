#include <iostream>
#include <string>

using namespace std;

template <class T>
class TreeNode {
	private:
		T val;
		TreeNode *parent;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode(T val, TreeNode<T> *left = NULL, TreeNode<T> *right = NULL, TreeNode<T> *parent = NULL) {
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
		
		TreeNode<T>* getParent() {
			return this->parent;
		}
		
		void setLeft(TreeNode<T> *left) {
			this->left = left;
		}
		
		void setRight(TreeNode<T> *right) {
			this->right = right;
		}
		
		void setParent(TreeNode<T> *parent) {
			this->parent = parent;
		}
		
		void print() {
			cout << this->val << endl;
		}
};

template <class U>
class BinaryTree {
	private:
		TreeNode<U> *root;
		
		
		
		void printTreeFromNode(TreeNode<U> *node) {
			if (node->getLeft() != NULL) printTreeFromNode(node->getLeft());
			cout << node->getVal() << " ";
			if (node->getRight() != NULL) printTreeFromNode(node->getRight());
		}
		
		void invertNode(TreeNode<U> *src) {
			if (src == NULL) return;
			TreeNode<U> *temp = src->getRight();
			src->setRight(src->getLeft());
			src->setLeft(temp);
			
			invertNode(src->getRight());
			invertNode(src->getLeft());
		}
		
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
						from->setRight(new TreeNode<U>(val, NULL, NULL, from));
						cout << val << " Inserted to the right of " << from->getVal() << endl;
					}
				} else if (val < from -> getVal()) {
					if (from->getLeft() != NULL) {
						insert(val, from->getLeft());
					} else {
						from->setLeft(new TreeNode<U>(val, NULL, NULL, from));
						cout << val << " Inserted to the left of " << from->getVal() << endl;
					}
				}
			}
		}
		
		void insertNode(TreeNode<U> *src) {
			if (src == NULL) return;
			this->insert(src->getVal());
			if (src->getRight() != NULL) insertNode(src->getRight());
			if (src->getLeft() != NULL) insertNode(src->getLeft());
		}
		
		TreeNode<U>* remove(U val, TreeNode<U> *from = NULL, bool traversed = false) {
			if (this->root == NULL) throw "Empty tree exception";
			
			if (from == NULL) {
				if (this->root->getVal() == val) {
					TreeNode<U> *response = this->root;
					if (this->root->getRight() != NULL) {
						this->root = this->root->getRight();
						this->root->setParent(NULL);
						this->insertNode(response->getLeft());
					} else {
						this->root = this->root->getLeft();
						this->root->setParent(NULL);
					}
					response->setLeft(NULL);
					response->setRight(NULL);
					return response;
				}
				
				if(!traversed)return this->remove(val, this->root, true);
			} else {
				if(from->getRight()!= NULL) {
					if (from->getRight()->getVal() == val) {
						TreeNode<U> *response = from->getRight();
						from->setRight(from->getRight()->getRight());
						this->insertNode(response->getLeft());
						response->setLeft(NULL);
						response->setRight(NULL);
						return response;
					}
				}
				
				if (from->getLeft() != NULL) {
					if (from->getLeft()->getVal() == val) {
						TreeNode<U> *response = from->getLeft();
						from->setLeft(from->getLeft()->getRight());
						this->insertNode(response->getLeft());
						response->setLeft(NULL);
						response->setRight(NULL);
						return response;
					}
				}
				return this->remove(val, from->getRight(), true);
				return this->remove(val, from->getLeft(), true);
			}
			
			return NULL;
		}
		
		bool find(U val, TreeNode<U> *from = NULL, bool traversed = false) {
			if (from == NULL) {
				if (traversed) return false;
				return find(val, this->root);
			}
			
			U fromVal = from->getVal();
			
			if (fromVal == val){
				return true;
			}else if (val > fromVal) {
				return find(val, from->getRight(), true);
			}else {
				return find(val, from->getLeft(), true);
			}
			
			return false;
		}
		
		void invert() {
			if (this->root == NULL) return;
			invertNode(this->root);
		}
		
		void print() {
			printTreeFromNode(this->root);
			cout << endl;
		}

};

int main() {
	BinaryTree<int> myTree;
	myTree.insert(12);
	myTree.insert(11);
	myTree.insert(2);
	myTree.insert(15);
	myTree.insert(123);
	myTree.insert(11);
	myTree.insert(3);
	myTree.insert(4);
	myTree.insert(155);
	
	myTree.print();
	myTree.remove(11);
	myTree.print();
	myTree.remove(12);
	myTree.print();
	
	cout << 15 << ": " << myTree.find(15) <<endl;
	cout << 11 << ": " << myTree.find(11) <<endl;
	cout << 155 << ": " << myTree.find(155) <<endl;
	cout << 12 << ": " << myTree.find(12) <<endl;
	
	myTree.invert();
	myTree.print();

}
