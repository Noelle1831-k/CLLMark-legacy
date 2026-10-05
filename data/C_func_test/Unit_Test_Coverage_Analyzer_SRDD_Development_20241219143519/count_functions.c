int count_functions(const char *source_code) {
    int function_count = 0;
    const char *function_keyword = "void"; 
    const char *ptr = source_code;
    for(int identifier = 1; (ptr = strstr(ptr, function_keyword)) != NULL; ) {
        ++function_count;
        ++ptr;
    }
    return function_count;
}