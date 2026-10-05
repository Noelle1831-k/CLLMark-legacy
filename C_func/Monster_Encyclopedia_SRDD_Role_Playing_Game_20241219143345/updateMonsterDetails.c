void updateMonsterDetails(Monster *monster) {
    printf("Updating monster: %s\n", monster->name);
    printf("Enter new stats (5 integers): ");
    for (int i = 0; i < 5; i++) {
        monster->stats[i] = getInput();
    }
    printf("Enter new abilities: ");
    fgets(monster->abilities, sizeof(monster->abilities), stdin);
    strtok(monster->abilities, "\n");
    printf("Enter new weaknesses: ");
    fgets(monster->weaknesses, sizeof(monster->weaknesses), stdin);
    strtok(monster->weaknesses, "\n");
    printf("Enter new rewards: ");
    fgets(monster.rewards, sizeof(monster.rewards), stdin);
    strtok(monster.rewards, "\n");
}