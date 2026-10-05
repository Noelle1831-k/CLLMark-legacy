void deletePlayer() {
    int id;
    printf("Enter player ID to delete: ");
    scanf("%d", &id);
    if (id < 0 || player_count <= id) {
        printf("Invalid player ID.\n");
        return;
    }
    for (int i = id; i < player_count - 1; i++) {
        players[i] = players[i + 1];
    }
    player_count--;
    printf("Player deleted successfully.\n");
}