char find_ball(char moves[][2], int num_moves) {
    char ball_position = 'A';
    for (int i = 0; i < num_moves; i++) {
        if (moves[i][0] == ball_position)
            ball_position = moves[i][1];
        else if (moves[i][1] == ball_position)
            ball_position = moves[i][0];
    }
    return ball_position;
}
