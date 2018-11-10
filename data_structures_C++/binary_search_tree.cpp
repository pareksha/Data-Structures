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
            ptr = root; // Initialise ptr with root
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
        int heightHelper(struct node* root_) {
            if(root_ == NULL) return 0;
            int l_height = heightHelper(root_ -> left);
            int r_height = heightHelper(root_ -> right);
            if(l_height > r_height) return l_height + 1;
            else return r_height + 1;
        }
        int numNodesHelper(struct node* root_) {
            if(root_ == NULL) return 0;
            int l_num = numNodesHelper(root_ -> left);
            int r_num = numNodesHelper(root_ -> right);
            return l_num + r_num + 1;
        }
        int hasPathSumHelper(int sum, struct node* root_) {
            
            if(root == NULL && sum == 0) return 1;
            
            else if(root == NULL && sum != 0) return 0;
            
            int sum1 = sum - root_ -> data;
            
            if(root_ -> left == NULL && root_ -> right == NULL) {
                if(sum1 == 0) return 1;
               // else return 0;
            } else if(root_ -> left != NULL && root_ -> right == NULL) {
                int flag = hasPathSumHelper(sum1, root_ -> left);
                if(flag) return 1;
                // else return 0;
            } else if(root_ -> right != NULL && root_ -> left == NULL) {
                int flag = hasPathSumHelper(sum1, root_ -> right);
                if(flag) return 1;
                // else return 0;
            } else {
                int flag1 = hasPathSumHelper(sum1, root_ -> left);
                int flag2 = hasPathSumHelper(sum1, root_ -> right);
                if(flag1 || flag2) return 1;
                // else return 0;
            }
        }
        void mirrorHelper(struct node* root_) {
            if(root_ == NULL) return;
            mirrorHelper(root_ -> left);
            mirrorHelper(root_ -> right);
            struct node* temp;
            temp = root_ -> left;
            root_ -> left = root_ -> right;
            root_ -> right = temp;
        }
        int similarTreesHelper(BST::node* root_1, BST::node* root_2) {
            if(root_1 == NULL && root_2 == NULL) return 1;
            // code will give segmentation fault if one is null and other is not
            // as we try to access left and/or right of null
            else if(root_1 == NULL && root_2 != NULL) return 0;
            else if(root_1 != NULL && root_2 == NULL) return 0;
            int compare_left = similarTreesHelper(root_1 -> left, root_2 -> left);
            int compare_rt = similarTreesHelper(root_1 -> right, root_2 -> right);
            if(compare_left && compare_rt) return 1;
            else return 0;
        }
        int identicalTreesHelper(BST::node* root_1, BST::node* root_2) {
            if(root_1 == NULL && root_2 == NULL) return 1;
            // code will give segmentation fault if one is null and other is not
            // as we try to access left and/or right of null
            else if(root_1 == NULL && root_2 != NULL) return 0;
            else if(root_1 != NULL && root_2 == NULL) return 0;
            int compare_left = identicalTreesHelper(root_1 -> left, root_2 -> left);
            int compare_rt = identicalTreesHelper(root_1 -> right, root_2 -> right);
            int compare_root = (root_1 -> data == root_2 -> data);
            if(compare_left && compare_rt && compare_root) return 1;
            else return 0;
        }
        int isMirrorHelper(BST::node* root_1, BST::node* root_2) {
            if(root_1 == NULL && root_2 == NULL) return 1;
            // code will give segmentation fault if one is null and other is not
            // as we try to access left and/or right of null
            else if(root_1 == NULL && root_2 != NULL) return 0;
            else if(root_1 != NULL && root_2 == NULL) return 0;
            int compare_left = isMirrorHelper(root_1 -> left, root_2 -> right);
            int compare_rt = isMirrorHelper(root_1 -> right, root_2 -> left);
            int compare_root = (root_1 -> data == root_2 -> data);
            if(compare_left && compare_rt && compare_root) return 1;
            else return 0;
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
            struct node* ptr = NULL;
            searchHelper(value, parent, ptr);
        }
        
        void delete_(int value) {
            struct node* parent = NULL;
            struct node* ptr = NULL;
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

        void height() {
            int max_height = heightHelper(root);
            cout << "Max height is " << max_height << endl;
        }

        void numNodes() {
            int num = numNodesHelper(root);
            cout << "Number of nodes is " << num << endl;
        }

        void maxValue() {
            if(root == NULL) {
                cout << "BST is empty" << endl;
                return;
            }
            struct node* ptr = root;
            while(ptr -> right != NULL) {
                ptr = ptr -> right;
            }
            cout << "Max Value is " << ptr -> data << endl;
        }

        void minValue() {
            if(root == NULL) {
                cout << "BST is empty" << endl;
                return;
            }
            struct node* ptr = root;
            while(ptr -> left != NULL) {
                ptr = ptr -> left;
            }
            cout << "Min Value is " << ptr -> data << endl;
        }

        void hasPathSum(int value) {
            int hasPath = hasPathSumHelper(value, root);
            if(hasPath) cout << "Path is present" << endl;
            else cout << "Path is NOT present" << endl;
        }

        void mirror() {
            mirrorHelper(root);
        }

        friend void identicalTrees(BST, BST);
        friend void similarTrees(BST, BST);
        friend void isMirror(BST, BST);
};

void identicalTrees(BST t1, BST t2) {
    int identical = t1.identicalTreesHelper(t1.root, t2.root);
    if(identical == 1) cout << "Trees are identical/same" << endl;
    else cout << "Trees are NOT identical/same" << endl;
}

void similarTrees(BST t1, BST t2) {
    int similar = t1.similarTreesHelper(t1.root, t2.root);
    if(similar == 1) cout << "Trees are similar" << endl;
    else cout << "Trees are NOT similar" << endl;
}

void isMirror(BST t1, BST t2) {
    int isMirr = t1.isMirrorHelper(t1.root, t2.root);
    if(isMirr) cout << "Trees are mirror images of each other" << endl;
    else cout << "Trees are NOT mirror images of each other" << endl;
}

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
    // Max Height
    tree.height();
    // Number of nodes
    tree.numNodes();
    // check if trees are same
    BST tree_1;
    tree_1.initialise();
    BST tree_2;
    tree_2.initialise();
    identicalTrees(tree_1, tree_2);
    // check if trees are similar
    BST tree_3;
    tree_3.initialise();
    BST tree_4;
    tree_4.initialise();
    tree_3.display();
    tree_4.display();
    similarTrees(tree_3, tree_4);
    identicalTrees(tree_3, tree_4);
    // Max and min value
    tree.maxValue();
    tree.minValue();
    // Check if path is present
    tree.hasPathSum(201);
    tree.hasPathSum(45);
    tree.display();
    tree.mirror();
    cout << endl << "-----------Mirror Image-----------" << endl;
    tree.display();
    // Checking if trees are mirror imgs
    BST mirrorTree;
    mirrorTree.initialise();
    cout << "Tree 1" << endl;
    mirrorTree.display();
    cout << "Tree 2" << endl;
    tree.display();
    isMirror(tree, mirrorTree);
}