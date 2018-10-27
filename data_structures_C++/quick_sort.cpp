#include<iostream>
using namespace std;

class QuicksortAlgo {
    private:
        int arr[10];
    public:
        void inputValues() {
            cout << "Enter 10 integers - " << endl;
            for(int i = 0; i < 10; i++) cin >> arr[i];
        }
        void Quicksort(int start, int end) {
            if(start >= end) return;
            int pivotIndex = Partition(start, end);
            Quicksort(start, pivotIndex - 1);
            Quicksort(pivotIndex + 1, end);
        }
        int Partition(int start, int end) {
            int pivot = arr[end];
            int p = start;
            for(int i = start; i < end; i++) {
                if(arr[i] < pivot) {
                    if(i == p) p += 1;
                    else {
                        int temp = arr[i];
                        arr[i] = arr[p];
                        arr[p] = temp;
                        p += 1;
                    }
                }
            }
            int temp = arr[p];
            arr[p] = pivot;
            arr[end] = temp;
            return p;            
        }
        void outputArray() {
            cout << "Resulting Array is - " << endl;
            for(int i = 0; i < 10; i++) cout << arr[i] << " ";
            cout << endl;
        }
};

main() {
    QuicksortAlgo q;
    q.inputValues();
    q.Quicksort(0, 9);
    q.outputArray();
}