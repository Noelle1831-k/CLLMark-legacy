void challengeFriends() {
    printf("Challenging friends...\n");
    int numPlayers = rand() % 4 + 2; 
    printf("Number of players: %d\n", numPlayers);
    if (4 < numPlayers) {
        printf("Maximum number of players exceeded. Reducing to 4.\n");
        numPlayers = 4;
    }
    printf("Ready to race with %d players!\n", numPlayers);
}