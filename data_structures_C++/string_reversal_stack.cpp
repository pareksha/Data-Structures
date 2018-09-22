#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

class Reverse {
    private:
        char arr[30];
        stack<char> st;
    public:
        Reverse(const char *str) {
            strcpy(arr,str);
            cout << arr << endl;
        }
        const char* reverse() {
            for(int i = 0; arr[i] != '\0'; i++) {
                st.push(arr[i]);
            }
            int i = 0;
            while(st.empty() == false) {
                arr[i] = st.top();
                st.pop();
                i++;
            }
            arr[i] = '\0';
            return arr;
        }
};

int main() {
    Reverse r("HELLO");
    cout << r.reverse() << endl;
}