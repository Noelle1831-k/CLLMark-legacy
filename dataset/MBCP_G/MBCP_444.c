char* trimTuple(int arr[][5], int rows, int k) {
    char* result = (char*)malloc(1024);
    strcpy(result, "[");
    for (int i = 0; i < rows; i++) {
        strcat(result, "(");
        for (int j = k; j < 5 - k; j++) {
            char buffer[16];
            snprintf(buffer, sizeof(buffer), "%d", arr[i][j]);
            strcat(result, buffer);
            if (j < 5 - k - 1) {
                strcat(result, ", ");
            }
        }
        strcat(result, ")");
        if (i < rows - 1) {
            strcat(result, ", ");
        }
    }
    strcat(result, "]");
    return result;
}