int isSuspiciousURL(const char *url) {
    const char *suspiciousPatterns[] = { "login", "secure", "update", "verify", NULL };
    for (int i = 0; suspiciousPatterns[i] != NULL; i++) {
        if (strstr(url, suspiciousPatterns[i])) {
            return 1;
        }
    }
    return 0;
}