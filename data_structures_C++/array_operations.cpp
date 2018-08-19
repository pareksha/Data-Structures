#include<iostream>
using namespace std;

template <class T>
class Array {
    private:
        T arr[30];
        int last;
    public:
        Array() {
            last = -1;
        }
        void update(T value, int index) {
            if(index <= last && index >= 0) {
            arr[index] = value;
            }
            else if(index < 0 || index >= 30) {
                cout << "Index incorrect!" << endl;
            }
            else if(index > last) {
                cout << "Index has not been filled yet!";
            }
        }
        void insert(T value) {
                last += 1;
                arr[last] = value;
        }
        void delete_value(T value) {
            int i, j, x;
            x = 0;
            for(i = 0; i <= last; i++) {
                if(arr[i] == value) {
                    x = 1;
                    break;
                }
            }
            if(i == last && x == 1) {
                last = last - 1;
            }
            else if(x == 1) {
                for(j = i; j < last; j++) {
                    arr[j] = arr[j + 1];
                }
                last = last - 1;
            }
        }
        void traverse() {
            int i;
            for(i = 0; i <= last; i++) {
                cout << "array[" << i << "] = " << arr[i] << endl;
            }
        }
        void bubble_sort() {
            int i, j, temp;
            for(i = 0; i <= last; i++) {
                for(j = last; j > i; j--) {
                    if(arr[j] < arr[j - 1]) {
                       temp = arr[j];
                       arr[j] = arr[j - 1];
                       arr[j - 1] = temp;
                    }
                }
            }
        }
        void selection_sort() {
            int i, j, min, temp, index_with_min;
            for(i = 0; i <= last; i++) {
                min = arr[i];
                index_with_min = i;
                for(j = i + 1; j <= last; j++) {
                    if(arr[j] < min) {
                        min = arr[j];
                        index_with_min = j;
                    }
                }
                temp = arr[i];
                arr[i] = arr[index_with_min];
                arr[index_with_min] = temp;
            }
        }
        int linear_search(T value) {
            int i;
            for(i = 0; i <= last; i++) {
                if(arr[i] == value) {
                    return 1;
                }
            }
            return 0;
        }
        int binary_search(T value) {
            selection_sort();
            int middle, temp_last, temp_first;
            temp_last = last;
            temp_first = 0;
            while(temp_first != temp_last) {
                middle = (temp_last - temp_first + 1)/2 + temp_first;
                if((temp_last - temp_first + 1) % 2 == 0) {
                    middle = middle - 1;
                }
                if(value == arr[middle]) {
                    return 1;
                }
                else if(value > arr[middle] && value <= arr[temp_last]) {
                    temp_first = middle + 1;
                }
                else if(value < arr[middle] && value >= arr[temp_first]) {
                    temp_last = middle - 1;
                }
                else if(value < arr[temp_first] || value > arr[temp_last]) {
                    return 0;
                }
            }
            if(arr[temp_first] == value) {
                return 1;
            }
            return 0;
        }
};

int main() {
    Array<char> char_arr;
    Array<int> int_arr;
    int number, value, x, choice;
    char repeat, val, y;
    do{
        cout << "Perform operation on which array? - 1. Numerical data OR 2. character data.\n";
        cin >> choice;
        cout << "\nWhich operation do you wish to perform on your array?\n1. Insertion\n2. Deletion\n3. Search\n4. Sort\n";
        cin >> number;
        switch(number) {
            case 1:
                cout << "Enter the value you want to insert: ";
                if(choice == 1) {
                    cin >> value;
                    int_arr.insert(value);
                    int_arr.traverse();
                }
                else if(choice == 2) {
                    cin >> val;
                    char_arr.insert(val);
                    char_arr.traverse();
                }
                break;
            case 2:
                cout << "Enter the value you want to delete: ";
                if(choice == 1) {
                    cin >> value;
                    int_arr.delete_value(value);
                    int_arr.traverse();
                }
                else if(choice == 2) {
                    cin >> val;
                    char_arr.delete_value(val);
                    char_arr.traverse();
                }
                break;
            case 3:
                cout << "Enter the value you want to search for: ";
                if(choice == 1) {
                    cin >> value;
                    x = int_arr.binary_search(value);
                    if(x == 1) cout << value << " present in arr!\n";
                    else cout << value << " not present in arr!\n";
                }
                else if(choice == 2) {
                    cin >> val;
                    y = char_arr.binary_search(val);
                    if(y == 1) cout << val << " present in arr!\n";
                    else cout << val << " not present in arr!\n";
                }
                break;
            case 4:
                if(choice == 1) {
                    int_arr.selection_sort();
                    int_arr.traverse();
                }
                else if(choice == 2) {
                    char_arr.selection_sort();
                    char_arr.traverse();
                }
                break;
            default:
                cout << "Entered option is invalid, want to try one more time? (y/n) ";
                cin >> repeat;
        }
        if(number==1 || number==2 || number==3 || number==4) {
            cout << "Want to perform another operation? (y/n) ";
            cin >> repeat;
        }
    }while(repeat == 'y');
}