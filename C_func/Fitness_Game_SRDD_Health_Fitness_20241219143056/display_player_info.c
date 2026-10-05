void display_player_info(Player player) {
    printf("Player Info:\n");
    printf("Name: %s\n", player.name[0] != '\0' ? player.name : "Unknown");
    printf("Score: %d\n", player.score);
    printf("Level: %d\n", player.level);
}