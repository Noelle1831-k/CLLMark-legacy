void remove_words(char list[][100], int list_size, char charlist[][100], int charlist_size) {
    for (int i = 0; i < list_size; i++) {
        for (int j = 0; j < charlist_size; j++) {
            char *ptr = strstr(list[i], charlist[j]);
            if (ptr) {
                int len = strlen(charlist[j]);
                memmove(ptr, ptr + len, strlen(ptr + len) + 1);
            }
        }
    }
}