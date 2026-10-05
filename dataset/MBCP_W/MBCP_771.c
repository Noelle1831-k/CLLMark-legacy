bool checkExpression(const char *exp) {
    int n = strlen(exp);
    char *stack = (char *)malloc(sizeof(char) * n);
    int top = -1;
    for (int i = 0; i < n; i++) {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            stack[++top] = exp[i];
        } else {
            if (top == -1) return false;
            if ((exp[i] == '}' && stack[top] != '{') ||
                (exp[i] == ']' && stack[top] != '[') ||
                (exp[i] == ')' && stack[top] != '(')) {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}
