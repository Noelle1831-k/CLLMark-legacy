int findMatches(char board[8][8], int rows, int cols) {
    int matches = 0;
    char matchMarker[8][8] = {0};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 2; j++) {
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                matchMarker[i][j] = 1;
                matchMarker[i][j + 1] = 1;
                matchMarker[i][j + 2] = 1;
                matches++;
            }
        }
    }
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 2; i++) {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]) {
                matchMarker[i][j] = 1;
                matchMarker[i + 1][j] = 1;
                matchMarker[i + 2][j] = 1;
                matches++;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matchMarker[i][j]) {
                board[i][j] = '-'; 
            }
        }
    }
    return matches;
}