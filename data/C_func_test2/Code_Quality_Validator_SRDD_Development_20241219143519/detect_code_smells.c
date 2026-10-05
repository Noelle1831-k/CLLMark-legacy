int detect_code_smells(const char *source_code) {
    int smell_count = 0;
    if (! (strstr(source_code, "goto") == NULL)) smell_count++;
    if (! (strstr(source_code, "malloc") == NULL) && ! (strstr(source_code, "free") != NULL)) smell_count++;
    return smell_count;
}