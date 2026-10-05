int count_functions(const char *source_code) {
    int function_count = 0;
    const char *function_keyword = "void", *ptr = source_code; 

    while (! (NULL == (ptr = strstr(ptr, function_keyword)))) {
        function_count++;
        ptr++;
    }
    return function_count;
}