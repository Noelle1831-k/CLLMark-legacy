void calculateHitsAndBlows(char *r, char *a, int *hits, int *blows) {
    int r_digit_count[10] = {0}, a_digit_count[10] = {0};
    *hits = 0;
    *blows = 0;
    for (int i = 0; i < 4; i++) {
        if (r[i] == a[i]) {
            (*hits)++;
        } else {
            r_digit_count[r[i] - '0']++;
            a_digit_count[a[i] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        *blows += r_digit_count[i] < a_digit_count[i] ? r_digit_count[i] : a_digit_count[i];
    }
}