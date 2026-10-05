char* remove_parenthesis(const char* str) {
    int n = strlen(str);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;
    int is_inside_parenthesis = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            is_inside_parenthesis = 1;
        } else if (str[i] == ')') {
            is_inside_parenthesis = 0;
        } else if (!is_inside_parenthesis) {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';
    return result;
}