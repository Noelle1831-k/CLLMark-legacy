int countChar(const char *str, char x) {
    int length = strlen(str);
    int initial_count = 0, total_count = 0;
    long long n = 10;  
    for (int i = 0; i < length; i++) {
        if (str[i] == x) {
            initial_count++;
        }
    }
    long long full_sequences = n / length;
    total_count = initial_count * full_sequences;
    long long remaining_characters = n % length;
    for (int i = 0; i < remaining_characters; i++) {
        if (str[i] == x) {
            total_count++;
        }
    }
    return total_count;
}