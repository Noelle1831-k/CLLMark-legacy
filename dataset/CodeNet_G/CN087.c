#define MAX_STACK_SIZE 100
#define EPSILON 0.00001
typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;
void initialize(Stack *s) {
    s->top = -1;
}
int is_empty(Stack *s) {
    return s->top == -1;
}
int is_full(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}
void push(Stack *s, double value) {
    if (!is_full(s)) {
        s->data[++(s->top)] = value;
    }
}
double pop(Stack *s) {
    if (!is_empty(s)) {
        return s->data[(s->top)--];
    }
    return 0.0;
}
double evaluate_rpn(char *expr) {
    char *token;
    Stack stack;
    double a, b;
    initialize(&stack);
    token = strtok(expr, " ");
    while (token != NULL) {
        if (sscanf(token, "%lf", &a) == 1) {
            push(&stack, a);
        } else {
            b = pop(&stack);
            a = pop(&stack);
            switch (token[0]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': if (fabs(b) > EPSILON) push(&stack, a / b); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}