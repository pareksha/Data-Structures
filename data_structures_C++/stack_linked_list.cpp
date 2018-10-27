#include<iostream>

using namespace std;

class LinkedListStack {
    private:
        struct node {
            int data;
            struct node* next;
        };
        struct node* start;
    public:
        LinkedListStack() {
            start = NULL;
        }
        void push(int value) {
            struct node* new_node = new struct node;
            new_node -> data = value;
            if(start == NULL) {
                start = new_node;
                new_node -> next = NULL;
            } else {
                new_node -> next = start;
                start = new_node;
            }
        }
        void pop() {
            struct node* temp = start;
            start = start -> next;
            delete temp;
        }
        bool empty() {
            if(start == NULL) return true;
            else return false;
        }
        int last() {
            if(start == NULL) cout << "Stack is empty." << endl;
            else cout << start -> data << endl;
        }
};

main() {
    LinkedListStack s;
    int number, value, x;
    char repeat;
    cout << "This is a stack.\n";
    do{
        cout << "\nWhich operation do you wish to perform on stack?\n1. push\n2. pop\n3. empty\n4. last\n";
        cin >> number;
        switch(number) {
            case 1:
                cout << "Enter the value you want to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                x = s.empty();
                if(x) cout << "Stack is empty!\n";
                else cout << "Stack is not empty!\n";
                break;
            case 4:
                s.last();
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