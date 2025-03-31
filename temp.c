char operator[100];
int operand[100], top1 = -1, top2 = -1;
void process() {
    int x = operand[top1--];
    int y = operand[top1--];
    char opr = operator[top2--];
    int result;
   if (opr == '+') result = y + x;
    else if (opr == '-') result = y - x;
    operand[++top1] = result;
}
int precedence(char opr) {
    if (opr == '+' || opr == '-') return 1;
    return -1;
}
int calculate(char* s) {
    top1 = top2 = -1; 
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == ' ') continue;
        if (isdigit(ch) || (ch == '-' && (i == 0 || s[i - 1] == '('|| s[i - 1] == ' '))) {
            int num = 0;
            int sign = 1;
            if (ch == '-') {
                sign = -1;
                i++;
                ch = s[i];
            }
            while (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                i++;
                ch = s[i];
            }
            i--;  
            operand[++top1] = num * sign;
        }
        else if (ch == '+' || ch == '-') {
            while (top2 != -1 && precedence(ch) <= precedence(operator[top2])) {
                process();
            }
            operator[++top2] = ch;
        }
        else if (ch == '(') {
            operator[++top2] = ch;
        }
        else if (ch == ')') {
            while (top2 != -1 && operator[top2] != '(') {
                process();
            }
            top2--; 
        }
    }
    while (top2 != -1) {
        process();
    }
    return operand[top1--];
}
