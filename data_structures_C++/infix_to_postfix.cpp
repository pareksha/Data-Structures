#include<iostream>
#include<string.h>
using namespace std;

class Stack {
    private:
        int last;
        char arr[30];
    public:
        Stack() {
            last = -1;
        }
        void push(char x) {
            arr[last + 1] = x;
            last += 1;
        }
        char pop() {
            char x = arr[last];
            last -= 1;
            return x;
        }
        char top() {
            return arr[last];
        }
        int isEmpty() {
            if(last == -1) return 1;
            else return 0;
        }
};

class InfixToPostfix {
    private:
        Stack S;
        char infix[30];
        char postfix[30];
    public:
        InfixToPostfix(const char* exp) {
            strcpy(infix, exp);
        }
        const char* convert() {
            int j = 0;
            for(int i = 0; infix[i] != '\0'; i++) {
                char char_ = infix[i];
                if(char_ == '^' || char_ == '/' || char_ == '*' || char_ == '+' || char_ == '-') {
                    if(char_ == '^') {
                        S.push(char_);
                    }
                    else if(char_ == '/') {
                        char top = S.top();
                        while(top == '^') {
                            postfix[j] = S.pop();
                            j++;
                            top = S.top();
                        }
                        S.push(char_);
                    }
                    else if(char_ == '*') {
                        char top = S.top();
                        while((top == '^' || top == '/') && S.isEmpty() == 0) {
                            postfix[j] = S.pop();
                            j++;
                            top = S.top();
                        }
                        S.push(char_);
                    }
                    else if(char_ == '+') {
                        char top = S.top();
                        while((top == '^' || top == '/' || top == '*') && S.isEmpty() == 0) {
                            postfix[j] = S.pop();
                            j++;
                            top = S.top();
                        }
                        S.push(char_);
                    }
                    else if(char_ == '-') {
                        char top = S.top();
                        while((top == '^' || top == '/' || top == '*' || top == '+') && S.isEmpty() == 0) {
                            postfix[j] = S.pop();
                            j++;
                            top = S.top();
                        }
                        S.push(char_);
                    }
                }
                else if (char_ == '(') {
                    S.push(char_);
                }
                else if (char_ == ')') {
                    while(S.top() != '(') {
                        postfix[j] = S.pop();
                        j++;
                    }
                    S.pop();
                }
                else {
                    postfix[j] = char_;
                    j++;
                }
            }
            while(S.isEmpty() == 0) {
                postfix[j] = S.pop();
                j++;
            }
            postfix[j] = '\0';
            return postfix;
        }
};

int main() {
    const char* infix_exp = "(A+(B*C-(D/E^F)*G)*H)";
    InfixToPostfix obj(infix_exp);
    const char* postfix_exp = obj.convert();
    cout << postfix_exp << endl;
}