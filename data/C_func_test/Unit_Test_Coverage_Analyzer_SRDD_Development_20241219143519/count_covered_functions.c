int count_covered_functions(const char *source_code, const char *test_code) {
    int covered_functions = 0;
    char **function_list = extract_functions(source_code);
    int function_count = count_functions(source_code);
    for (int i = 0; i < function_count; i++) {
        if (strstr(test_code, function_list[i]) != NULL) {
            covered_functions++;
        }
        free(function_list[i]);
    }
    free(function_list);
    return covered_functions;
}