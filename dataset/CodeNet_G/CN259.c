#define MAX_EXPR_LENGTH 100000
typedef struct {
    int nums[MAX_EXPR_LENGTH];
    char ops[MAX_EXPR_LENGTH];
    int num_top, op_top;
} Stack;
int mod_pow(int a, int b, int p) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % p;
        }
        a = (a * a) % p;
        b /= 2;
    }
    return result;
}
int mod_inverse(int a, int p) {
    return mod_pow(a, p - 2, p);
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '(' || op == ')') return 0;
    return -1;
}
void apply_operation(Stack *stack, char op, int p) {
    if (stack->num_top < 2) return;
    int b = stack->nums[--stack->num_top];
    int a = stack->nums[--stack->num_top];
    int result;
    if (op == '+') {
        result = (a + b) % p;
    } else if (op == '-') {
        result = (a - b + p) % p;
    } else if (op == '*') {
        result = (a * b) % p;
    } else if (op == '/') {
        if (b == 0) {
            stack->nums[stack->num_top++] = -1;
            return;
        }
        result = (a * mod_inverse(b, p)) % p;
    } else {
        return;
    }
    stack->nums[stack->num_top++] = result;
}
int compute_expression(int p, char *expr) {
    Stack stack = {.num_top = 0, .op_top = 0};
    int i, num = 0, num_flag = 0;
    int len = strlen(expr);
    for (i = 0; i < len; ++i) {
        if (isdigit(expr[i])) {
            num = num * 10 + (expr[i] - '0');
            num_flag = 1;
        } else {
            if (num_flag) {
                stack.nums[stack.num_top++] = num % p;
                num = 0;
                num_flag = 0;
            }
            if (isspace(expr[i])) continue;
            if (expr[i] == '(') {
                stack.ops[stack.op_top++] = expr[i];
            } else if (expr[i] == ')') {
                while (stack.op_top > 0 && stack.ops[stack.op_top - 1] != '(') {
                    apply_operation(&stack, stack.ops[--stack.op_top], p);
                }
                if (stack.op_top > 0) --stack.op_top; 
            } else {
                while (stack.op_top > 0 && precedence(stack.ops[stack.op_top - 1]) >= precedence(expr[i])) {
                    apply_operation(&stack, stack.ops[--stack.op_top], p);
                }
                stack.ops[stack.op_top++] = expr[i];
            }
        }
    }
    if (num_flag) {
        stack.nums[stack.num_top++] = num % p;
    }
    while (stack.op_top > 0) {
        apply_operation(&stack, stack.ops[--stack.op_top], p);
    }
    if (stack.num_top == 0 || stack.nums[0] == -1) return -1;
    return stack.nums[0];
}
void calculate_finite_field_operations() {
    char buffer[MAX_EXPR_LENGTH + 15]; 
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (strcmp(buffer, "0:\n") == 0) break;
        int p;
        char expr[MAX_EXPR_LENGTH + 1];
        if (sscanf(buffer, " %d : %[^\n]", &p, expr) != 2) continue;
        int result = compute_expression(p, expr);
        if (result == -1) {
            printf("NG\n");
        } else {
            printf("%s = %d (mod %d)\n", expr, result, p);
        }
    }
}
