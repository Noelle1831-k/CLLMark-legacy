void sortMoves(char moves[MAX_MOVES][50], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(moves[j], moves[j + 1]) > 0) {
                char temp[50];
                strcpy(temp, moves[j]);
                strcpy(moves[j], moves[j + 1]);
                strcpy(moves[j + 1], temp);
            }
        }
    }
}