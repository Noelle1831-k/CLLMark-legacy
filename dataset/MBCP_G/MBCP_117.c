void listToFloat(char testList[][2][20], int rows, char result[][2][20]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            float num = atof(testList[i][j]);
            sprintf(result[i][j], "%.2f", num);
        }
    }
}