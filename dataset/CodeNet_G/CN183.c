void check_winner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'b') {
                printf("b\n");
                return;
            } else if (board[i][0] == 'w') {
                printf("w\n");
                return;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'b') {
                printf("b\n");
                return;
            } else if (board[0][i] == 'w') {
                printf("w\n");
                return;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'b') {
            printf("b\n");
            return;
        } else if (board[0][0] == 'w') {
            printf("w\n");
            return;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'b') {
            printf("b\n");
            return;
        } else if (board[0][2] == 'w') {
            printf("w\n");
            return;
        }
    }
    printf("NA\n");
}
