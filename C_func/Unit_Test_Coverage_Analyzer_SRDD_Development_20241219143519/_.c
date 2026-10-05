char **extract_functions(const char *source_code) {
    char **function_list = (char **)malloc(100 * sizeof(char *)); 
    int function_index = 0;
    const char *function_keyword = "void"; 
    const char *ptr = source_code;
    while ((ptr = strstr(ptr, function_keyword)) != NULL) {
        char *function_name = (char *)malloc(50 * sizeof(char)); 
        sscanf(ptr, "void %s", function_name);
        function_list[function_index++] = function_name;
        ptr++;
    }
    return function_list;
}