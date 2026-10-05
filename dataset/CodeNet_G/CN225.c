#define MAX_WORDS 10000
typedef struct {
    int in_degree;
    int out_degree;
} NodeDegree;
int canFormShiritori(int n, char words[][33]) {
    NodeDegree degree[26] = {0};
    int start, end, i;
    for (i = 0; i < n; i++) {
        int len = strlen(words[i]);
        start = words[i][0] - 'a';
        end = words[i][len - 1] - 'a';
        degree[start].out_degree++;
        degree[end].in_degree++;
    }
    int start_end_match = 0;
    int in_out_balanced = 1;
    for (i = 0; i < 26; i++) {
        if (degree[i].in_degree != degree[i].out_degree) {
            in_out_balanced = 0;
            break;
        }
    }
    int first_word_start = words[0][0] - 'a';
    int last_word_end = words[n-1][strlen(words[n-1]) - 1] - 'a';
    if (first_word_start == last_word_end)
        start_end_match = 1;
    return start_end_match && in_out_balanced;
}
void evaluateDatasets(int datasets[][33], int words[], int datasets_count) {
    int i;
    for (i = 0; i < datasets_count; i++) {
        if (canFormShiritori(words[i], datasets[i]))
            printf("OK\n");
        else
            printf("NG\n");
    }
}