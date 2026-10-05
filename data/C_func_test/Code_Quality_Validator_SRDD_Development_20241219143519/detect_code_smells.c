int detect_code_smells(const char *source_code) {
    int smell_count = 0;
    if (NULL != strstr(source_code, "goto")) ++smell_count;
    if (NULL != strstr(source_code, "malloc") && NULL == strstr(source_code, "free")) ++smell_count;
    return smell_count;
}