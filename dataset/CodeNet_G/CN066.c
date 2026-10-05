char check_winner(char board[9]) {
    const int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}  
    };
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] != 's' &&
            board[wins[i][0]] == board[wins[i][1]] &&
            board[wins[i][1]] == board[wins[i][2]]) {
            return board[wins[i][0]];
        }
    }
    return 'd';
}
void process_input(char *input) {
    for (int i = 0; i < strlen(input); i += 9) {
        char result = check_winner(&input[i]);
        printf("%c\n", result);
    }
}