int findErrorPosition(int L, int entries[]) {
    int stack[1000];
    int top = -1;
    for (int i = 0; i < L; ++i) {
        int cat = entries[i];
        if (cat > 0) {
            if (top < 999) {
                stack[++top] = cat;
            }
        } else {
            if (top >= 0 && stack[top] == -cat) {
                --top;
            } else {
                return i + 1;
            }
        }
    }
    return top == -1 ? 0 : L + 1;
}