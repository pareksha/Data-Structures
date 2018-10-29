#include<iostream>
using namespace std;

class BST {
    private:
        struct node {
            int data;
            struct node* left;
            struct node* right;
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
        void preorderTraversalHelper(struct node* root_) {
            if(root_ == NULL) return;
            cout << root_ -> data << "\t";
            preorderTraversalHelper(root_ -> left);
            preorderTraversalHelper(root_ -> right);
        }
        void postorderTraversalHelper(struct node* root_) {
            if(root_ == NULL) return;
            postorderTraversalHelper(root_ -> left);
            postorderTraversalHelper(root_ -> right);
            cout << root_ -> data << "\t";
        }
        void inorderTraversalHelper(struct node* root_) {
            if(root_ == NULL) return;
            inorderTraversalHelper(root_ -> left);
            cout << root_ -> data << "\t";
            inorderTraversalHelper(root_ -> right);
        }
        void searchHelper(int value, struct node* &parent, struct node* &ptr) {
            for(int i = 0; i < 7; i++) {
                if(ptr == NULL) {
                    cout << value << " is NOT present in BST." << endl;
                    ptr = NULL;
                    parent = NULL;
                    return;
                } else if(value < ptr -> data) {
                    if(ptr -> left == NULL) {
                        cout << value << " is NOT present in BST." << endl;
                        ptr = NULL;
                        parent = NULL;
                        return;
                    } else {
                        parent = ptr;
                        ptr = ptr -> left;
                    }
                } else if(value > ptr -> data) {
                    if(ptr -> right == NULL) {
                        cout << value << " is NOT present in BST." << endl;
                        ptr = NULL;
                        parent = NULL;
                        return;
                    } else {
                        parent = ptr;
                        ptr = ptr -> right;
                    }
                } else {
                    cout << value << " is present in BST." << endl;
                    return;
                }
            }
        }
    public:
        BST() {
            root = NULL;
        }
        void initialise() {
            int arr[7];
            cout << "Enter 7 values - " << endl; 
            for(int i = 0; i < 7; i++) {
                cin >> arr[i];
            }
            for(int i = 0; i < 7; i++) {
                insert(arr[i]);
            }
        }
        void insert(int value) {
            struct node* new_node = new struct node;
            new_node -> data = value;
            new_node -> left = NULL;
            new_node -> right = NULL;
            if(root == NULL) {
                root = new_node;
            } else {
                struct node* parent = root;
                while(1) {
                    if(value < parent -> data) {
                        if(parent -> left == NULL) {
                            parent -> left = new_node;
                            return;
                        }
                        parent  = parent -> left;
                    } else if(value > parent -> data){
                        if(parent -> right == NULL) {
                            parent -> right = new_node;
                            return;
                        }
                        parent  = parent -> right;
                    } else {
                        cout << value << " is already present." << endl;
                        return;
                    }
                }
            }
        }
        void display() {
            displayHelper(root, 0);
        }
        void preorderTraversal() {
            cout << "Preorder Traversal is \t";
            preorderTraversalHelper(root);
            cout << endl;
        }
        void inorderTraversal() {
            cout << "Inorder Traversal is \t";
            inorderTraversalHelper(root);
            cout << endl;
        }
        void postorderTraversal() {
            cout << "Postorder Traversal is \t";
            postorderTraversalHelper(root);
            cout << endl;
        }

        void search(int value) {
            cout << "Searching for " << value << endl;
            struct node* parent = NULL;
            struct node* ptr = root;
            searchHelper(value, parent, ptr);
        }
        
        void delete_(int value) {
            struct node* parent = NULL;
            struct node* ptr = root;
            searchHelper(value, parent, ptr);
            if(parent == NULL && ptr == NULL) return;
            cout << "Deleting value " << value << endl;
            if(ptr -> left == NULL && ptr -> right == NULL) {
                if(ptr == parent -> left) parent -> left = NULL;
                else if(ptr == parent -> right) parent -> right = NULL;
                delete ptr;
            } else if(ptr -> left != NULL && ptr -> right == NULL) {
                if(ptr == parent -> left) parent -> left = ptr -> left;
                else if(ptr == parent -> right) parent -> right = ptr -> left;
                delete ptr;
            } else if (ptr -> right != NULL && ptr -> left == NULL) {
                if(ptr == parent -> left) parent -> left = ptr -> right;
                else if(ptr == parent -> right) parent -> right = ptr -> right;
                delete ptr;
            } else if (ptr -> left != NULL && ptr -> right != NULL) {
                struct node* max = ptr -> right;
                struct node* max_parent = ptr;
                if(max -> left == NULL) {
                    ptr -> data = max -> data;
                    ptr -> right = max -> right;
                    delete max;
                }
                else {
                    while(max -> left != NULL) {
                        max_parent = max;
                        max = max -> left;
                    }
                    if(max -> right == NULL) max_parent -> left = NULL;
                    else if(max -> right != NULL) max_parent -> left = max -> right;
                    ptr -> data = max -> data;
                    delete max;
                }
            }
        }
};

main() {
    BST tree;
    // Initialise/Insertion
    tree.initialise();
    // Display
    tree.display();
    // Traversal
    tree.preorderTraversal();
    tree.postorderTraversal();
    tree.inorderTraversal();
    // Search
    tree.search(123);
    tree.search(14);
    // Delete
    tree.delete_(9);
    tree.display();
    tree.delete_(11);
    tree.display();
    tree.delete_(67);
    tree.display();
    tree.delete_(23);
    tree.display();
}