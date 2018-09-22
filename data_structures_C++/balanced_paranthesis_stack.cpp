#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

class BalancedParanthesis {
    private:
        char arr[30];
        stack<char> st; 
    public:
        BalancedParanthesis(const char* str) {
            strcpy(arr, str);
        }
        int checkBalance() {
            if(strcmp(arr, "") == 0) {
                return 1;
            }
            for(int i = 0; arr[i] != '\0'; i++) {
                char bracket = arr[i];
                if(bracket == '(' || bracket == '{' || bracket == '[') {
                    st.push(bracket);
                }
                else {
                    if(st.empty() == true) {
                        return 0;
                    }
                    char top = st.top();
                    if((top == '(' && bracket == ')') || (top == '{' && bracket == '}') || (top == '[' && bracket == ']')) {
                        st.pop();
                    }
                    else {
                        return 0;
                    }
                }
            }
            if(st.empty() == true) {
                return 1;
            }
        }
};

int main() {
    BalancedParanthesis b("(){}[{()}]");
    int isBalanced = b.checkBalance();
    if(isBalanced == 0) {
        cout << "Paranthesis is NOT balanced!" << endl;
    } else {
        cout << "Paranthesis is balanced!" << endl;
    }
} 