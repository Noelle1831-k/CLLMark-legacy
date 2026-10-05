int validateDescription(const char *description) {
    if (strlen(description) == 0 || strlen(description) > 99) {
        return 0; 
    }
    return 1; 
}