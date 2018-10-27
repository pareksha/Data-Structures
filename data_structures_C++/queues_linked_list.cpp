#include<iostream>
using namespace std;

class QueueLinkedList {
    private:
        struct node {
            int data;
            struct node* next;
        };
        struct node* start;
        struct node* end;
    public:
        QueueLinkedList() {
            start = NULL;
            end = NULL;
        }
        void enqueue(int value) {
            struct node* new_node = new struct node;
            new_node -> data = value;
            if(start == NULL) {
                new_node -> next = NULL;
                start = new_node;
                end = new_node;
            } else {
                new_node -> next = NULL;
                end -> next = new_node;
                end = new_node;
            }
        }
        void dequeue() {
            if(start == NULL) cout << "Queue is EMPTY" << endl;
            else {
                struct node* temp = start;
                start = start -> next;
                delete temp;
                if(start == NULL) end = NULL;
            }
        }
        int front() {
            if(start == NULL) cout << "Queue is EMPTY" << endl;
            else return end -> data;
        }
        int back() {
            if(start == NULL) cout << "Queue is EMPTY" << endl;
            else return start -> data;
        }
        bool empty() {
            if(start == NULL) return true;
            else return false;
        }
        int length() {
            struct node* temp = start;
            if(start == NULL) return 0;
            int count = 0;
            while(temp != end) {
                count += 1;
                temp = temp -> next;
            }
            return count + 1;
        }
};

main() {
    QueueLinkedList q;
    int number, value, x;
    char repeat;
    cout << "This is a queue.\n";
    do{
        cout << "\nWhich operation do you wish to perform on queue?\n1. enqueue\n2. dequeue\n3. front\n4. back\n5. empty\n6. length\n";
        cin >> number;
        switch(number) {
            case 1:
                cout << "Enter the value you want to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << q.front() << endl;
                break;
            case 4:
                cout << q.back() << endl;
                break;
            case 5:
                cout << q.empty() << endl;
                break;
            case 6:
                cout << q.length() << endl;
                break;
            default:
                cout << "Entered option is invalid, want to try one more time? (y/n) ";
                cin >> repeat;
        }
        if(number==1 || number==2 || number==3 || number==4 || number==5 || number==6) {
            cout << "Want to perform another operation? (y/n) ";
            cin >> repeat;
        }
    }while(repeat == 'y');
}