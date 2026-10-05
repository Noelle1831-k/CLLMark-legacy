void recruitPlayers() {
    printf("\n===== RECRUIT PLAYERS =====\n");
    if (playerCount >= MAX_PLAYERS) {
        printf("Your team is already full. Cannot recruit more players.\n");
        return;
    }
    char name[MAX_NAME_LEN];
    int skill, stamina;
    printf("Enter player name: ");
    scanf("%s", name);
    skill = randomInt(50, 100);
    stamina = randomInt(50, 100);
    Player newPlayer = createPlayer(name, skill, stamina);
    addPlayer(newPlayer);
    printf("Player %s recruited successfully!\n", name);
}