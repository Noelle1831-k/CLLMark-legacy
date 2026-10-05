Monster createMonster() {
    Monster monster;
    printf("Enter monster name: ");
    fgets(monster.name, sizeof(monster.name), stdin);
    strtok(monster.name, "\n");
    printf("Enter monster stats (5 integers): ");
    for (int i = 0; i < 5; i++) {
        monster.stats[i] = getInput();
    }
    printf("Enter monster abilities: ");
    fgets(monster.abilities, sizeof(monster.abilities), stdin);
    strtok(monster.abilities, "\n");
    printf("Enter monster weaknesses: ");
    fgets(monster.weaknesses, sizeof(monster.weaknesses), stdin);
    strtok(monster.weaknesses, "\n");
    printf("Enter monster rewards: ");
    fgets(monster.rewards, sizeof(monster.rewards), stdin);
    strtok(monster.rewards, "\n");
    monster.defeated = 0;
    return monster;
}