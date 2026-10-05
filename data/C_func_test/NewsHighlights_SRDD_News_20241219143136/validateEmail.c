int validateEmail(const char* email) {
    const char* at = strchr(email, '@');
    const char* dot = strrchr(email, '.');
    if (at && dot && at < dot) {
        return 1;
    }
    return 0;
}