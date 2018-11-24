#include<iostream>
using namespace std;

class BST {
    private:
        struct node {
            int data;
            struct node* left;
            struct node* right;
            int height;
        };
        struct node* root;
        void displayHelper(struct node* root_, int spaces) {
            if(root_ == NULL) return;
            spaces += 1;
            displayHelper(root_ -> right, spaces);
            cout << endl;
            for (int i = 0; i < spaces; i++) cout << "      ";
            cout << root_ -> data << endl;
            displayHelper(root_ -> left, spaces);
        }
        int setHeight(struct node* root_) {
            int left_height, right_height;
            // Left tree height
            if(root_ -> left == NULL) left_height = 0;
            else left_height = root_ -> left -> height;
            // Right tree height
            if(root_ -> right == NULL) right_height = 0;
            else right_height = root_ -> right -> height;
            root_ -> height = 1 + max(left_height, right_height);
        }
        struct node* rotateRight(struct node* root_) {
            struct node* new_root;
            new_root = root_ -> left;
            root_ -> left = root_ -> left -> right;
            new_root -> right = root_;
            
            // Set root_ ht before setting new_root ht because root_ is the subtree of new_root
            // If root_ ht is incorrect, new_root ht will also be incorrect
            setHeight(root_);
            setHeight(new_root);

            return new_root;
        }
        struct node* rotateLeft(struct node* root_) {
            struct node* new_root;
            new_root = root_ -> right;
            root_ -> right = root_ -> right -> left;
            new_root -> left = root_;

            // Set root_ ht before setting new_root ht because root_ is the subtree of new_root
            // If root_ ht is incorrect, new_root ht will also be incorrect
            setHeight(root_);
            setHeight(new_root);

            return new_root;
        }
        struct node* insertHelper(struct node* root_, int value) {
            // Normal insertion
            if(root_ == NULL) {
                struct node* new_node = new struct node;
                new_node -> left = NULL;
                new_node -> right = NULL;
                new_node -> height = 1;
                new_node -> data = value;
                return new_node;
            } else if(root_ -> data > value) {
                root_ -> left = insertHelper(root_ -> left, value);
            } else if(root_ -> data < value) {
                root_ -> right = insertHelper(root_ -> right, value);
            } else if(root_ -> data == value) {
                cout << value << " is already present" << endl;
                return root_;
            }

            // Update Height
            int left_height, right_height;
            // Left tree height
            if(root_ -> left == NULL) left_height = 0;
            else left_height = root_ -> left -> height;
            // Right tree height
            if(root_ -> right == NULL) right_height = 0;
            else right_height = root_ -> right -> height;
            root_ -> height = 1 + max(left_height, right_height);

            // Check balance factor
            int balanceFactor = left_height - right_height;
            // Balance
            if(balanceFactor > 1) {
                if(value < root_ -> left -> data) root_ =  rotateRight(root_);
                else if(value > root_ -> left -> data) {
                    root_ -> left = rotateLeft(root_ -> left);
                    root_ =  rotateRight(root_);
                }
            } else if(balanceFactor < -1) {
                if(value > root_ -> right -> data) root_ = rotateLeft(root_);
                else if(value < root_ -> right -> data) {
                    root_ -> right = rotateRight(root_ -> right);
                    root_ = rotateLeft(root_);
                }
            }

            return root_;
        }
        struct node* getInorderSucc(struct node* root_) {
            struct node* temp = root_ -> right;
            while(temp -> left != NULL) {
                temp = temp -> left;
            }
            return temp;
        }
        int getBalanceFactor(struct node* root_) {
            int left_height, right_height;
            // Left tree height
            if(root_ -> left == NULL) left_height = 0;
            else left_height = root_ -> left -> height;
            // Right tree height
            if(root_ -> right == NULL) right_height = 0;
            else right_height = root_ -> right -> height;
            root_ -> height = 1 + max(left_height, right_height);

            // Return balance factor
            return left_height - right_height;
        }
        struct node* del_helper(struct node* root_, int value) {
            // Normal delete as in BST
            if (root_ == NULL) return root_;
            else if (value < root_ -> data) root_ -> left = del_helper(root_ -> left, value); 
            else if(value > root_ -> data) root_ -> right = del_helper(root_ -> right, value);
            else {
                // Node to be deleted found
                if(root_ -> left == NULL && root_ -> right == NULL) { 
                    struct node* temp = root_;
                    root_ = NULL;
                    delete temp;
                    return root_;   // Important because root_ is NULL now, accessing it's left or rt will cause segmentation error
                } else if(root_ -> left == NULL && root_ -> right != NULL) {
                    struct node* temp = root_ -> right;
                    *root_ = *(root_ -> right);     // This copies the node, if we do root_ = root_ -> right, 
                    delete temp;                    // it only increments the root_ ptr to point to root_ -> right.
                } else if(root_ -> left != NULL && root_ -> right == NULL) {
                    struct node* temp = root_ -> left;
                    *root_ = *(root_ -> left);
                    delete temp;
                } else {
                    struct node* inorder_succ = getInorderSucc(root_);
                    root_ -> data = inorder_succ -> data;
                    root_ -> right = del_helper(root_ -> right, inorder_succ -> data);
                }
            }

            // Update Height
            int left_height, right_height;
            // Left tree height
            if(root_ -> left == NULL) left_height = 0;
            else left_height = root_ -> left -> height;
            // Right tree height
            if(root_ -> right == NULL) right_height = 0;
            else right_height = root_ -> right -> height;
            root_ -> height = 1 + max(left_height, right_height);

            // Balancing
            int balance_factor = getBalanceFactor(root_);

            if(balance_factor > 1) {
                int left_balance = getBalanceFactor(root_ -> left);
                if(left_balance >= 0) {
                    root_ = rotateRight(root_);
                } else {
                    root_ -> left = rotateLeft(root_ -> left);
                    root_ = rotateRight(root_);
                }
            } else if(balance_factor < -1) {
                int rt_balance = getBalanceFactor(root_ -> right);
                if(rt_balance <= 0) {
                    root_ = rotateLeft(root_);
                } else {
                    root_ -> right = rotateRight(root_ -> right);
                    root_ = rotateLeft(root_);
                }
            }
            return root_; 
        } 
    public:
        BST() {
            root = NULL;
        }
        void insert(int value) {
            root = insertHelper(root, value);
        }
        void display() {
            displayHelper(root, 0);
        }
        void delete_node(int value) {
            root = del_helper(root, value);
        } 
};

main() {
    BST tree;
    // Insertion
    tree.insert(23);
    tree.display();
    cout << "---------------------" << endl;
    tree.insert(27);
    tree.display();
    cout << "---------------------" << endl;
    tree.insert(89);
    tree.display();
    cout << "---------------------" << endl;
    tree.insert(12);
    tree.display();
    cout << "---------------------" << endl;
    tree.insert(20);
    tree.display();
    cout << "---------------------" << endl;
    tree.insert(2);
    tree.display();
    cout << "---------------------" << endl;
    tree.insert(108);
    tree.display();
    cout << "---------------------" << endl;
    tree.delete_node(23);
    tree.display();
    cout << "---------------------" << endl;
    tree.delete_node(89);
    tree.display();
    cout << "---------------------" << endl;
    tree.delete_node(108);
    tree.display();
    cout << "---------------------" << endl;
    tree.delete_node(27);
    tree.display();
}