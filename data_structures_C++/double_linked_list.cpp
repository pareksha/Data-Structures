#include<iostream>
using namespace std;

class DoubleLinkedList {
    private:
        struct node {
            int data;
            struct node* pre_link;
            struct node* next_link;
        };
        struct node* start;
        struct node* end;
    public:
        DoubleLinkedList() {
            start = NULL;
            end = NULL; 
        }
        int search(int value) {
            if(start == NULL) {
               return 0;
            }
            struct node* cur = start;
            while(cur != NULL) {
                if(cur -> data == value) {
                    return 1;
                }
                cur = cur -> next_link;
            }
            return 0;
        }
        void insert(int new_data) {
            if(search(new_data) == 0) {
                struct node* cur = find_loc(new_data);
                struct node* new_node = new struct node;
                new_node -> data = new_data;
                if(cur == NULL) {
                    start = new_node;
                    new_node -> next_link = NULL;
                    new_node -> pre_link = NULL;
                    end = new_node;
                }
                else if(cur -> pre_link == NULL) {
                    start = new_node;
                    cur -> pre_link = new_node;
                    new_node -> next_link = cur;
                    new_node -> pre_link = NULL;
                }
                else if(cur -> next_link == NULL && cur -> data < new_data) {
                    new_node -> pre_link = cur;
                    new_node -> next_link = NULL;
                    cur -> next_link = new_node;
                    end = new_node;
                }
                else {
                    new_node -> pre_link = cur -> pre_link;
                    new_node -> next_link = cur;
                    cur -> pre_link = new_node;
                    new_node -> pre_link -> next_link = new_node;
                }
                return;
            }
            else {
                cout << new_data << " already present!" << endl;
            }
        }
        void delete_node(int value) {
            if(search(value) == 1) {
                struct node* cur = find_loc(value);
                if(cur == NULL) {
                    start = start -> next_link;
                }
                else if(cur -> next_link == NULL && cur -> pre_link == NULL) {
                    start = NULL;
                    end = NULL;
                }
                else if(cur -> pre_link == NULL) {
                    start = cur -> next_link;
                    cur -> next_link -> pre_link = NULL;
                }
                else if(cur -> next_link == NULL) {
                    end = cur -> pre_link;
                    cur -> pre_link -> next_link = NULL;
                }
                else {
                    cur -> pre_link -> next_link = cur -> next_link;
                    cur -> next_link -> pre_link = cur -> pre_link;
                }
            }
            else {
                cout << value << " is not present!" << endl;
            }
        }
        struct node* find_loc(int value) {
            struct node* cur;
            cur = start;
            while(1) {
                if(cur == NULL) {
                    return cur;
                }
                else if(cur -> data < value && cur -> next_link != NULL) {
                    cur = cur -> next_link;
                }
                else if(cur -> data >= value) {
                    return cur;
                }
                else if(cur -> next_link == NULL) {
                    return cur;
                }
            }
        }
        void traverse() {
            if(start == NULL) {
                cout << "List is empty!";
            }
            struct node* cur = start;
            int i = 1;
            cout << "\n";
            while(cur != NULL) {
                cout << "Node " << i << " = " << cur -> data << endl;
                cur = cur -> next_link;
                i++;
            }
            cout << "\n";
        }
        void reverse_traverse() {
            if(end == NULL) {
                cout << "List is empty!";
            }
            struct node* cur = end;
            int i = 1;
            cout << "\n";
            while(cur != NULL) {
                cout << "Reverse Node " << i << " = " << cur -> data << endl;
                cur = cur -> pre_link;
                i++;
            }
            cout << "\n";
        }
};

main() {
    DoubleLinkedList list;
    int number, value, x;
    char repeat;
    cout << "This is a numerical data linked list.\n";
    do{
        cout << "\nWhich operation do you wish to perform on linked list?\n1. Insertion\n2. Deletion\n3. Search\n4. Traversal\n5. Reverse Traversal\n";
        cin >> number;
        switch(number) {
            case 1:
                cout << "Enter the value you want to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter the value you want to delete: ";
                cin >> value;
                list.delete_node(value);
                break;
            case 3:
                cout << "Enter the value you want to search for: ";
                cin >> value;
                x = list.search(value);
                if(x == 1) cout << value << " present in list!\n";
                else cout << value << " not present in list!\n";
                break;
            case 4:
                list.traverse();
                break;
            case 5:
                list.reverse_traverse();
                break;
            default:
                cout << "Entered option is invalid, want to try one more time? (y/n) ";
                cin >> repeat;
        }
        if(number==1 || number==2 || number==3 || number==4 || number ==5) {
            cout << "Want to perform another operation? (y/n) ";
            cin >> repeat;
        }
    }while(repeat == 'y');
}