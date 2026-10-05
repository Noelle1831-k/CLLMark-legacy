void classifySnake(int n, char snakes[][201]) {
    for (int i = 0; i < n; i++) {
        char *snake = snakes[i];
        int len = strlen(snake);
        if (len >= 6 && snake[0] == '>' && snake[1] == '\'') {
            int eqCount = 0;
            int j = 2;
            while (j < len && snake[j] == '=') {
                eqCount++;
                j++;
            }
            if (eqCount > 0 && snake[j] == '#' && j + 1 + eqCount < len) {
                j++;
                int eqCount2 = 0;
                while (j < len && snake[j] == '=') {
                    eqCount2++;
                    j++;
                }
                if (eqCount2 == eqCount && j < len && snake[j] == '~' && j + 1 == len) {
                    printf("A\n");
                    continue;
                }
            }
        }
        if (len >= 5 && snake[0] == '>' && snake[1] == '^') {
            int j = 2;
            while (j + 1 < len && snake[j] == 'Q' && snake[j + 1] == '=') {
                j += 2;
            }
            if (j + 1 == len && snake[j] == '~' && snake[j + 1] == '~') {
                printf("B\n");
                continue;
            }
        }
        printf("NA\n");
    }
}
