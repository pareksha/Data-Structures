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
            if(!root_) return;
            cout << root_ -> data << "\t";
            preorderTraversalHelper(root_ -> left);
            preorderTraversalHelper(root -> right);
        }
        void postorderTraversalHelper(struct node* root_) {
            if(!root_) return;
            postorderTraversalHelper(root_ -> left);
            postorderTraversalHelper(root -> right);
            cout << root_ -> data << "\t";
        }
        void inorderTraversalHelper(struct node* root_) {
            if(!root_) return;
            inorderTraversalHelper(root_ -> left);
            cout << root_ -> data << "\t";
            inorderTraversalHelper(root -> right);
        }
        int flag;
    public:
        BST() {
            root = NULL;
            flag = 0;
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
            preorderTraversalHelper(root);
        }
        void inorderTraversal() {
            inorderTraversalHelper(root);
        }
        void postorderTraversal() {
            postorderTraversalHelper(root);
        }
        struct node* search(int value) {
            struct node* parent = NULL;
            struct node* ptr = root;
            for(int i = 0; i < 7; i++) {
                if(ptr == NULL) {
                    cout << value << " is NOT present in BST." << endl;
                    return NULL;
                } else if(value < ptr -> data) {
                    if(ptr -> left == NULL) {
                        cout << value << " is NOT present in BST." << endl;
                        return NULL;
                    } else {
                        parent = ptr;
                        ptr = ptr -> left;
                    }
                } else if(value > ptr -> data) {
                    if(ptr -> right == NULL) {
                        cout << value << " is NOT present in BST." << endl;
                        return NULL;
                    } else {
                        parent = ptr;
                        ptr = ptr -> right;
                    }
                } else {
                    cout << value << " is present in BST." << endl;
                    if(root == ptr) flag = 1;
                    return parent;
                }
            }
        }
        
        void delete_(int value) {
            struct node* parent = search(value);
            if(parent == NULL) {
                if(flag = 0) return;
                else {
                    flag = 0;
                    if(root -> left == NULL && root -> right == NULL) {
                        struct node* temp = root;
                        root = NULL;
                        delete temp;
                    } else if(root -> left != NULL && root -> right == NULL) {
                        struct node* temp = root;
                        root = root -> left;
                        delete temp;
                    } else if (root -> right != NULL && root -> left == NULL) {
                        struct node* temp = root;
                        root = root -> right;
                        delete temp;
                    } else if (root -> left != NULL && root -> right != NULL) {
                        struct node* max = root -> right;
                        struct node* max_parent = root;
                        if(max -> left == NULL) {
                            root -> data = max -> data;
                            root -> right = max -> right;
                            delete max;
                        }
                        else {
                            while(max -> left != NULL) {
                                max_parent = max;
                                max = max -> left;
                            }
                            if(max -> left == NULL && max -> right == NULL) {
                                max_parent -> left = NULL;
                            } else if(max -> left != NULL && max -> right == NULL) {
                                max_parent -> left = max -> left;
                            } else if(max -> left == NULL && max -> right != NULL) {
                                max_parent -> left = max -> right;
                            }
                            root -> data = max -> data;
                            delete max;
                        }
                    }
                }
            } else if(parent -> left != NULL && parent -> left -> data == value) {
                if(parent -> left -> left == NULL && parent -> left -> right == NULL) {
                    struct node* temp = parent -> left;
                    parent -> left = NULL;
                    delete temp;
                } else if(parent -> left -> left != NULL && parent -> left -> right == NULL) {
                    struct node* temp = parent -> left;
                    parent -> left = parent -> left -> left;
                    delete temp;
                } else if (parent -> left -> right != NULL && parent -> left -> left == NULL) {
                    struct node* temp = parent -> left;
                    parent -> left = parent -> left -> right;
                    delete temp;
                } else if (parent -> left -> left != NULL && parent -> left -> right != NULL) {
                    struct node* max = parent -> left -> right;
                    struct node* max_parent = parent -> left;
                    if(max -> left == NULL) {
                        parent -> left -> data = max -> data;
                        parent -> left -> right = max -> right;
                        delete max;
                    }
                    else {
                        while(max -> left != NULL) {
                            max_parent = max;
                            max = max -> left;
                        }
                        if(max -> left == NULL && max -> right == NULL) {
                            max_parent -> left = NULL;
                        } else if(max -> left != NULL && max -> right == NULL) {
                            max_parent -> left = max -> left;
                        } else if(max -> left == NULL && max -> right != NULL) {
                            max_parent -> left = max -> right;
                        }
                        parent -> left -> data = max -> data;
                        delete max;
                    }
                }
            } else if (parent -> right != NULL && parent -> right -> data == value) {
                if(parent -> right -> left == NULL && parent -> right -> right == NULL) {
                    struct node* temp = parent -> right;
                    parent -> right = NULL;
                    delete temp;
                } else if(parent -> right -> left != NULL && parent -> right -> right == NULL) {
                    struct node* temp = parent -> right;
                    parent -> right = parent -> right -> left;
                    delete temp;
                } else if (parent -> right -> right != NULL && parent -> right -> left == NULL) {
                    struct node* temp = parent -> right;
                    parent -> right = parent -> right -> right;
                    delete temp;
                } else if (parent -> right -> left != NULL && parent -> right -> right != NULL) {
                    struct node* max = parent -> right -> right;
                    struct node* max_parent = parent -> right;
                    if(max -> left == NULL) {
                        parent -> right -> data = max -> data;
                        parent -> right -> right = max -> right;
                        delete max;
                    }
                    else {
                        while(max -> left != NULL) {
                            max_parent = max;
                            max = max -> left;
                        }
                        if(max -> left == NULL && max -> right == NULL) {
                            max_parent -> left = NULL;
                        } else if(max -> left != NULL && max -> right == NULL) {
                            max_parent -> left = max -> left;
                        } else if(max -> left == NULL && max -> right != NULL) {
                            max_parent -> left = max -> right;
                        }
                        parent -> right -> data = max -> data;
                        delete max;
                    }
                }
            }
        }
};

main() {
    BST tree;
    tree.initialise();
    tree.display();
    // tree.search(12);
    // tree.search(14);
    tree.delete_(9);
    tree.display();
}