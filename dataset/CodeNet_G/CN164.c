void ohajiki_game(int sequence[], int seq_len) {
    int marbles = 32;
    int jiroTurn = 0;
    while (marbles > 0) {
        int ichiroTake = (marbles - 1) % 5;
        if (ichiroTake == 0) ichiroTake = 1;
        marbles -= ichiroTake;
        printf("%d\n", marbles);
        if (marbles == 0) break;
        int jiroTake = sequence[jiroTurn % seq_len];
        if (jiroTake > marbles) jiroTake = marbles;
        marbles -= jiroTake;
        printf("%d\n", marbles);
        jiroTurn++;
    }
}