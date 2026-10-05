void listifyList(int count, char* list[]) {
    for (int i = 0; i < count; i++) {
        printf("{");
        for (int j = 0; j < strlen(list[i]); j++) {
            printf("\"%c\"", list[i][j]);
            if (j < strlen(list[i]) - 1) {
                printf(", ");
            }
        }
        printf("}");
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}