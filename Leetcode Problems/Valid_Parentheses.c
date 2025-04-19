bool isValid(char* s) {
    int stack[100000], top = -1;

    int isEmpty() {
        return (top == -1) ? 1 : 0;
    }

    void push(char val) {
        if (top < 100000 - 1) { 
            top++;
            stack[top] = val;
        }
    }

    void pop() {
        if (!isEmpty()) { 
            top--;
        }
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else if (s[i] == ')') {
            if (!isEmpty() && stack[top] == '(') { 
                pop();
            } else {
                return false;
            }
        } else if (s[i] == '}') {
            if (!isEmpty() && stack[top] == '{') {
                pop();
            } else {
                return false;
            }
        } else if (s[i] == ']') {
            if (!isEmpty() && stack[top] == '[') {
                pop();
            } else {
                return false;
            }
        }
    }

    return isEmpty();
}
