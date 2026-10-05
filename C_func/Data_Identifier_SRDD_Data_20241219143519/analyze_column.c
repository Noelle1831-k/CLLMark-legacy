void analyze_column(char **column, int rows, char *result) {
    int is_int = 1, is_float = 1, is_bool = 1;
    for (int i = 0; i < rows; i++) {
        if (!is_integer(column[i])) is_int = 0;
        if (!is_float(column[i])) is_float = 0;
        if (!is_boolean(column[i])) is_bool = 0;
    }
    if (is_int) strcpy(result, "Integer");
    else if (is_float) strcpy(result, "Float");
    else if (is_bool) strcpy(result, "Boolean");
    else strcpy(result, "String");
}