#define MAX_WORDS 100
char** startWithp(char* strArr[], int size, int* returnSize) {
    char** result = (char**)malloc(MAX_WORDS * sizeof(char*));
    int count = 0;
    for (int i = 0; i < size; i++) {
        char* token = strtok(strArr[i], " ");
        while (token != NULL) {
            if (token[0] == 'P' || token[0] == 'p') {
                result[count] = (char*)malloc(strlen(token) + 1);
                strcpy(result[count], token);
                count++;
            }
            token = strtok(NULL, " ");
        }
    }
    *returnSize = count;
    return result;
}
