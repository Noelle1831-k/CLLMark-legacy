#define MAX_RESULT_LEN 1024
void concatenateElements(char *result, char *list[], int size) {
    strcpy(result, " ");
    for (int i = 0; i < size; ++i) {
        strcat(result, list[i]);
        if (i < size - 1) {
            strcat(result, " ");
        }
    }
}