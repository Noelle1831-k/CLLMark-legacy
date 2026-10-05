const char *textMatchString(const char *text) {
    if (strncmp(text, "python", 6) == 0) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}