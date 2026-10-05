int lenLog(char* list[], int size) {
    if (size <= 0) return 0;
    int min_len = strlen(list[0]);
    for (int i = 1; i < size; i++) {
        int current_len = strlen(list[i]);
        if (current_len < min_len) {
            min_len = current_len;
        }
    }
    return min_len;
}