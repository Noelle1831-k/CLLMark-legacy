void groupTuples(char tuples[][2][100], int n, char result[][100][100], int *resultSize) {
    int i, j, index = 0;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < index; j++) {
            if (strcmp(result[j][0], tuples[i][0]) == 0) {
                int k = 1;
                while (strlen(result[j][k]) > 0) k++;
                strcpy(result[j][k], tuples[i][1]);
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(result[index][0], tuples[i][0]);
            strcpy(result[index][1], tuples[i][1]);
            index++;
        }
    }
    *resultSize = index;
}