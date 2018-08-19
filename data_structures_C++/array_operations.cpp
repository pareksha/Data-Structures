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
    Array<int> int_arr;
    int_arr.insert(30);
    int_arr.insert(10);
    int_arr.insert(20);
    int_arr.insert(5);
    int_arr.delete_value(70);
    int_arr.selection_sort();
    int_arr.traverse();
    int x = int_arr.binary_search(30);
    cout << x << endl;

    Array<char> char_arr;
    char_arr.insert('C');
    char_arr.insert('q');
    char_arr.insert('B');
    char_arr.insert('y');
    char_arr.update('x', 3);
    char_arr.delete_value('A');
    x = char_arr.binary_search('x');
    cout << x << endl;
    char_arr.bubble_sort();
    x = char_arr.binary_search('q');
    cout << x << endl;
    char_arr.traverse();
}