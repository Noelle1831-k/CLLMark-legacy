#define MAX_WORDS 50000
#define MAX_LENGTH 201
int match(const char *word, const char *slate) {
    int n = strlen(word);
    int m = strlen(slate);
    if (slate[m - 1] == '*') {
        for (int i = 0; i < m - 1; ++i) {
            if (slate[i] == '?') continue;
            if (slate[i] != word[i]) return 0;
        }
        return 1;
    }
    if (slate[0] == '*') {
        int j = n - 1;
        for (int i = m - 1; i > 0; --i) {
            if (slate[i] == '?') continue;
            if (slate[i] != word[j--]) return 0;
        }
        return 1;
    }
    if (n != m) return 0;
    for (int i = 0; i < m; ++i) {
        if (slate[i] == '?') continue;
        if (slate[i] != word[i]) return 0;
    }
    return 1;
}
int main() {
    int n, m;
    char words[MAX_WORDS][MAX_LENGTH];
    char slates[MAX_WORDS][MAX_LENGTH];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", words[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", slates[i]);
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (match(words[j], slates[i])) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
