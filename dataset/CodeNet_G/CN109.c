int evaluate(char *expression) {
    int values[100]; 
    char ops[100]; 
    int val_index = -1; 
    int ops_index = -1; 
    int i = 0;
    while (expression[i] != '=') {
        if (isdigit(expression[i])) {
            int val = 0;
            while (isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            values[++val_index] = val;
        }
        else if (expression[i] == '(') {
            ops[++ops_index] = expression[i];
            i++;
        }
        else if (expression[i] == ')') {
            while (ops[ops_index] != '(') {
                int b = values[val_index--];
                int a = values[val_index--];
                char op = ops[ops_index--];
                if (op == '+') values[++val_index] = a + b;
                else if (op == '-') values[++val_index] = a - b;
                else if (op == '*') values[++val_index] = a * b;
                else if (op == '/') values[++val_index] = a / b;
            }
            ops_index--; 
            i++;
        }
        else {
            while (ops_index != -1 &&  ((ops[ops_index] == '+' || ops[ops_index] == '-') && 
                   (expression[i] == '+' || expression[i] == '-')) || 
                   ((ops[ops_index] == '*' || ops[ops_index] == '/') && 
                   (expression[i] == '*' || expression[i] == '/')) ) {
                int b = values[val_index--];
                int a = values[val_index--];
                char op = ops[ops_index--];
                if (op == '+') values[++val_index] = a + b;
                else if (op == '-') values[++val_index] = a - b;
                else if (op == '*') values[++val_index] = a * b;
                else if (op == '/') values[++val_index] = a / b;
            }
            ops[++ops_index] = expression[i];
            i++;
        }
    }
    while (ops_index != -1) {
        int b = values[val_index--];
        int a = values[val_index--];
        char op = ops[ops_index--];
        if (op == '+') values[++val_index] = a + b;
        else if (op == '-') values[++val_index] = a - b;
        else if (op == '*') values[++val_index] = a * b;
        else if (op == '/') values[++val_index] = a / b;
    }
    return values[val_index];
}