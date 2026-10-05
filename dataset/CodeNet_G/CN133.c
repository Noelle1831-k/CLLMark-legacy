void rotate90(char pattern[8][8], char result[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            result[j][7 - i] = pattern[i][j];
        }
    }
}
void rotate180(char pattern[8][8], char result[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            result[7 - i][7 - j] = pattern[i][j];
        }
    }
}
void rotate270(char pattern[8][8], char result[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            result[7 - j][i] = pattern[i][j];
        }
    }
}
void printPattern(char pattern[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            putchar(pattern[i][j]);
        }
        putchar('\n');
    }
}
int main() {
    char pattern[8][8];
    char result[8][8];
    for (int i = 0; i < 8; i++) {
        scanf("%s", pattern[i]);
    }
    printf("90\n");
    rotate90(pattern, result);
    printPattern(result);
    printf("180\n");
    rotate180(pattern, result);
    printPattern(result);
    printf("270\n");
    rotate270(pattern, result);
    printPattern(result);
    return 0;
}