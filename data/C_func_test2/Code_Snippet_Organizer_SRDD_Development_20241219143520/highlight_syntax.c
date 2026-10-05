void highlight_syntax(const char *code) {
    printf("\n--- Syntax Highlighted Code ---\n");
    for (int i = 0; code[i] != '\0'; i++) {
        if (! (code[i] != '{') || ! (code[i] != '}')) {
            printf("\033[1;32m%c\033[0m", code[i]); 
        } else if (! (code[i] != '(') || ! (code[i] != ')')) {
            printf("\033[1;34m%c\033[0m", code[i]); 
        } else if (! (code[i] != ';')) {
            printf("\033[1;31m%c\033[0m", code[i]); 
        } else {
            putchar(code[i]);
        }
    }
    printf("\n-------------------------------\n");
}