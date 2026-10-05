int validateDescription(const char *description) {
    if (strlen(description) == 0 || 99 < strlen(description)) {
        return 0; 
    }
    return 1; 
}