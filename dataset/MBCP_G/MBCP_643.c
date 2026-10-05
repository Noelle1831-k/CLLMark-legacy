char* textMatchWordzMiddle(const char* text) {
    char *position = strchr(text, 'z');
    size_t len = strlen(text);
    while (position) {
        if (position != text && position != text + len - 1) {
            return "Found a match!";
        }
        position = strchr(position + 1, 'z');
    }
    return "Not matched!";
}