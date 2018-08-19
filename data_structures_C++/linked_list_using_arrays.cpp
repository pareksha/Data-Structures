#include<iostream>
using namespace std;


class LinkedListUsingArray {
    private:
        int arr[30][2];
        int start;
        int last;
    public:
        LinkedListUsingArray() {
            start = -1;
            last = -1;
        }
        int search(int value) {
            if(start == -1) {
               return 0;
            }
            int cur = start;
            while(cur != -1) {
                if(arr[cur][0] == value) {
                    return 1;
                }
                cur = arr[cur][1];
            }
            return 0;
        }
        void insert(int new_data) {
            if(search(new_data) == 0) {
                int pre = find_loc(new_data);
                int cur;
                last += 1;
                if(pre == -1) {
                    cur = start;
                    start = last;
                }
                else {
                    cur = arr[pre][1];
                    arr[pre][1] = last;
                }
                arr[last][0] = new_data;
                arr[last][1] = cur;
                return;
            }
            else {
                cout << new_data << " already present!" << endl;
            }
        }
        void delete_node(int value) {
            if(search(value) == 1) {
                int cur;
                int pre = find_loc(value);
                if(pre == -1) {
                    start = arr[start][1];
                }
                else {
                    cur = arr[pre][1];               
                    arr[pre][1] = arr[cur][1];
                }
                last = last - 1;
            }
            else {
                cout << value << " is not present!" << endl;
            }
        }
        int find_loc(int value) {
            int pre;
            int cur;
            cur = start;
            pre = -1;
            while(cur <= last) {
                if(cur == -1) {
                    return pre;
                }
                else if(arr[cur][0] < value) {
                    pre = cur;
                    cur = arr[cur][1];
                }
                else if(arr[cur][0] >= value) {
                    return pre;
                }
            }
        }
        void traverse() {
            int cur = start;
            int i = 1;
            cout << "\n";
            while(cur != -1) {
                cout << "Node " << i << " = " << arr[cur][0] << endl;
                cur = arr[cur][1];
                i++;
            }
            cout << "\n";
        }
};

main() {
    LinkedListUsingArray list;
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