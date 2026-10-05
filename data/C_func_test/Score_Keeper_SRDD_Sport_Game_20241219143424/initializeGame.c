void initializeGame() {
    setTeamName(0, "Team A");
    setTeamName(1, "Team B");
    gameStartTime = time(NULL);
    *(scores + 0) = 0;
    *(scores + 1) = 0;
    gameActive = 1;
}