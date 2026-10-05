void find_words(char *text) {
    char *words[100], *token;
    int count[100] = {0}, max_count = 0, max_length = 0;
    int n = 0, max_count_index = 0, max_length_index = 0;
    token = strtok(text, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[n] = token;
            count[n] = 1;
            n++;
        }
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < n; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_count_index = i;
        }
        if (strlen(words[i]) > max_length) {
            max_length = strlen(words[i]);
            max_length_index = i;
        }
    }
    printf("%s %s", words[max_count_index], words[max_length_index]);
}
