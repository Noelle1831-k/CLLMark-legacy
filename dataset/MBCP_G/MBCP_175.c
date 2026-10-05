bool isValidParentheses(const char *str) {
    int n = strlen(str);
    char stack[n];
    int top = -1;
    for (int i = 0; i < n; i++) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;
            char last = stack[top--];
            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                return false;
            }
        }
    }
    return top == -1;
}
