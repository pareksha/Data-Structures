#include<iostream>
using namespace std;

class Queues {
    private:
        int arr[20];
        int first;
        int last;
    public:
        Queues() {
            first = -1;
            last = -1;
        }
        void enqueue(int value) {
            if((last + 1)%20 == first) {
                cout << "Queue is FULL" << endl;
            } else {
                arr[last + 1] = value;
                last = (last + 1)%20;
                if(first == -1) first = 0;
            }
        }
        void dequeue() {
            if (first == -1 && last == -1) cout << "Queue is EMPTY" << endl;
            else {
                first = (first + 1)%20;
                if((last + 1)%20 == first) {
                    last = -1;
                    first = -1;
                }
            }
        }
        int front() {
            if (first == -1 && last == -1) cout << "Queue is EMPTY" << endl;
            else return arr[first];
        }
        int back() {
            if (first == -1 && last == -1) cout << "Queue is EMPTY" << endl;
            else return arr[last];
        }
        bool empty() {
            if (first == -1 && last == -1) return true;
            else return false;
        }
        int length() {
            if (first == -1 && last == -1) return 0;
            else return (last - first + 20)%20 + 1;
        }
};

main() {
    Queues q;
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