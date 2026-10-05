int count_matching_rings(const char *search_string, int N, char rings[][11]) {
    int count = 0;
    int search_len = strlen(search_string);
    for (int i = 0; i < N; i++) {
        char extended_ring[21];
        strcpy(extended_ring, rings[i]);
        strncat(extended_ring, rings[i], search_len - 1);
        if (strstr(extended_ring, search_string) != NULL) {
            count++;
        }
    }
    return count;
}