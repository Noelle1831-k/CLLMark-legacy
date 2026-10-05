bool canClearSequence(int *sequence, int length) {
    int stack[100];
    int top = -1;
    for (int i = 0; i < length; i++) {
        if (top >= 0 && stack[top] == sequence[i]) {
            while (top >= 0 && stack[top] == sequence[i]) {
                top--;
            }
        } else {
            stack[++top] = sequence[i];
        }
    }
    return top == -1;
}
int main() {
    int N;
    scanf("%d", &N);
    int sequence[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }
    if (canClearSequence(sequence, N)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}