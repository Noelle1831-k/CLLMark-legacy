int validateInput(const char *move, const char *decision) {
    if (strlen(move) > 0 && strlen(decision) > 0) {
        return 1;
    }
    return 0;
}