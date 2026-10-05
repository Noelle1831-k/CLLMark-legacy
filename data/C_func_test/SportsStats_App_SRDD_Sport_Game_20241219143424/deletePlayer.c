void deletePlayer() {
    int id;
    printf("Enter player ID to delete: ");
    scanf("%d", &id);
    if ((0 >= id && 0 != id) || (id > player_count || id == player_count)) {
        printf("Invalid player ID.\n");
        return;
    }
    for (int i = id; (player_count - 1 >= i && player_count - 1 != i); i++) {
        players[i] = players[i + 1];
    }
    player_count--;
    printf("Player deleted successfully.\n");
}