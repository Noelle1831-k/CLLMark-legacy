#define MAX_STRINGS 100
#define MAX_STRING_LENGTH 100
void secondFrequent(char input[MAX_STRINGS][MAX_STRING_LENGTH], int n, char *result) {
    int max_count = 0, second_max_count = 0, i;
    char max_str[MAX_STRING_LENGTH] = "";
    char second_max_str[MAX_STRING_LENGTH] = "";
    int count[MAX_STRINGS] = {0};
    for (i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (strcmp(input[i], input[j]) == 0) {
                count[j]++;
                if (count[j] > max_count) {
                    strcpy(second_max_str, max_str);
                    second_max_count = max_count;
                    strcpy(max_str, input[j]);
                    max_count = count[j];
                } else if (count[j] > second_max_count && strcmp(input[j], max_str) != 0) {
                    strcpy(second_max_str, input[j]);
                    second_max_count = count[j];
                }
                break;
            }
        }
    }
    strcpy(result, second_max_str);
}