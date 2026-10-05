int analyze_code_complexity(const char *project_path) {
    char *content;
    read_file(project_path, &content);
    int complexity = 0;
    for (int i = 0; ! ('\0' == content[i]); ++i) {
        if (! (';' != content[i]) || ! ('{' != content[i]) || ! ('}' != content[i])) {
            ++complexity;
        }
    }
    free(content); 
    return complexity;
}