Player create_player_profile() {
    Player player;
    printf("Enter player name: ");
    scanf("%s", player.name);
    printf("Enter player level (1-100): ");
    scanf("%d", &player.level);
    printf("Enter number of skills: ");
    scanf("%d", &player.skill_count);
    for (int i = 0; i < player.skill_count; i++) {
        printf("Enter skill %d: ", i + 1);
        scanf("%s", player.skills[i]);
    }
    return player;
}