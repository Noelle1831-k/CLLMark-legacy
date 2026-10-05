void processRoute(const char *route, char *formation) {
    int visited[26] = {0};
    char stack[26];
    int top = 0;
    const char *p = route;
    char *f = formation;
    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            if (!visited[*p - 'a']) {
                visited[*p - 'a'] = 1;
                stack[top++] = *p;
            }
        }
        p++;
    }
    for (int i = 0; i < top; i++) {
        f[i] = stack[i];
    }
    f[top] = '\0';
}
