int getInputInt() {
    int input;
    if (scanf("%d", &input) != 1) {
        while (getchar() != '\n'); 
        return -1;
    }
    return input;
}