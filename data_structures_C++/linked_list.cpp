#include<iostream>
using namespace std;


class LinkedList {
    private:
        struct node {
            int data;
            struct node* link;
        };
        struct node* start;
    public:
        LinkedList() {
            start = NULL;
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
                cur = cur -> link;
            }
            return 0;
        }

        void insert(int new_data) {
            if(search(new_data) == 0) {
                struct node* pre = find_loc(new_data);
                struct node* new_node = new struct node;
                struct node* cur;
                new_node -> data = new_data;
                if(pre == NULL) {
                    cur = start;
                    start = new_node;
                }
                else {
                    cur = pre -> link;
                    pre -> link = new_node;
                }
                new_node -> link = cur;
                return;
            }
            else {
                cout << new_data << " already present!" << endl;
            }
        }

        void delete_node(int value) {
            if(search(value) == 1) {
                struct node* pre = find_loc(value);
                if(pre == NULL) {
                    start = start -> link;
                }
                else {
                    pre -> link = pre -> link -> link;
                }
            }
            else {
                cout << value << " is not present!" << endl;
            }
        }

        struct node* find_loc(int value) {
            struct node* pre;
            struct node* cur;
            cur = start;
            pre = NULL;
            while(1) {
                if(cur == NULL) {
                    return pre;
                }
                else if(cur -> data < value) {
                    pre = cur;
                    cur = cur -> link;
                }
                else if(cur -> data >= value) {
                    return pre;
                }
            }
        }


        void traverse() {
            struct node* cur = start;
            int i = 1;
            cout << "\n";
            while(cur != NULL) {
                cout << "Node " << i << " = " << cur -> data << endl;
                cur = cur -> link;
                i++;
            }
            cout << "\n";
        }
};


int main() {
    LinkedList list;
    int number, value, x;
    char repeat;
    cout << "This is a numerical data linked list.\n";
    do{
        cout << "\nWhich operation do you wish to perform on linked list?\n1. Insertion\n2. Deletion\n3. Search\n";
        cin >> number;
        switch(number) {
            case 1:
                cout << "Enter the value you want to insert: ";
                cin >> value;
                list.insert(value);
                list.traverse();
                break;
            case 2:
                cout << "Enter the value you want to delete: ";
                cin >> value;
                list.delete_node(value);
                list.traverse();
                break;
            case 3:
                cout << "Enter the value you want to search for: ";
                cin >> value;
                x = list.search(value);
                if(x == 1) cout << value << " present in list!\n";
                else cout << value << " not present in list!\n";
                break;
            default:
                cout << "Entered option is invalid, want to try one more time? (y/n) ";
                cin >> repeat;
        }
        if(number==1 || number==2 || number==3) {
            cout << "Want to perform another operation? (y/n) ";
            cin >> repeat;
        }
    }while(repeat == 'y');
}
