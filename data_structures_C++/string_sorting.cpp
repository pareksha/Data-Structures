#include<iostream>
#include<string.h>

using namespace std;

class StringArray {
    private:
        char str[7][20];
    public:
        void getData() {
            cout << "Enter seven names:\n";
            int i;
            for(i = 0; i < 7; i++) {
                cin >> str[i];
            }
        }
        void bubble_sort() {
            int i, j;
            char temp[20];
            for(i = 0; i < 7; i++) {
                for(j = 7; j > i; j--) {
                    if(strcmp(str[j-1], str[j]) > 0) {
                        strcpy(temp, str[j]);
                        strcpy(str[j], str[j - 1]);
                        strcpy(str[j - 1], temp);
                    }
                }
            }
        }
        void selection_sort() {
            int i, j, index_with_min;
            char temp[20];
            for(i = 0; i <= 7; i++) {
                index_with_min = i;
                for(j = i + 1; j <= 7; j++) {
                    if(strcmp(str[j], str[index_with_min]) < 0) {
                        index_with_min = j;
                    }
                }
                strcpy(temp, str[i]);
                strcpy(str[i], str[index_with_min]);
                strcpy(str[index_with_min], temp);
            }
        }
        void traverse() {
            int i;
            cout << "\nSorted names are:";
            for(i = 0; i < 7; i++) {
                cout << str[i] << "\n";
            }
        }
};

main()
{
    StringArray arr;
    arr.getData();
    int choice;
    cout << "\nWhich sorting menthod do you prefer? 1. Bubble sort OR 2. Selection sort\n";
    cin >> choice;
    if(choice == 1) {
        arr.bubble_sort();
        arr.traverse();
    } else if(choice == 2) {
        arr.selection_sort();
        arr.traverse();
    } else {
        cout << "Wrong Choice!";
    }
}