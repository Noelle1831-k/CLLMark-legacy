int contains_keyword(const char *str) {
    return strstr(str, "the") || strstr(str, "this") || strstr(str, "that");
}
void decrypt_caesar_cipher(const char *input, char *output) {
    int shift;
    for (shift = 0; shift < 26; ++shift) {
        int i;
        for (i = 0; input[i] != '\0'; ++i) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                output[i] = 'a' + (input[i] - 'a' + shift) % 26;
            } else {
                output[i] = input[i];
            }
        }
        output[i] = '\0';
        if (contains_keyword(output)) {
            return;
        }
    }
}
