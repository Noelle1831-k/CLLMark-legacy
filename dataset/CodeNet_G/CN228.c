void generate_signal(int n, int* digits) {
    const char* segments[] = {
        "0111111", 
        "0000110", 
        "1011011", 
        "1001111", 
        "1100110", 
        "1101101", 
        "1111101", 
        "0000111", 
        "1111111", 
        "1101111"  
    };
    char current_state[8] = "0000000";
    for (int i = 0; i < n; i++) {
        const char* target = segments[digits[i]];
        for (int j = 0; j < 7; j++) {
            if (current_state[j] != target[j]) {
                putchar('1');
            } else {
                putchar('0');
            }
        }
        putchar('\n');
        strcpy(current_state, target);
    }
}