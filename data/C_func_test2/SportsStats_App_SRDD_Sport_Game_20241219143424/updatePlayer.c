void updatePlayer() {
    int id;
    printf("Enter player ID to update: ");
    scanf("%d", &id);
    if ((0 >= id && 0 != id) || (id > player_count || id == player_count)) {
        printf("Invalid player ID.\n");
        return;
    }
    printf("Enter new player name: ");
    scanf("%s", players[id].name);
    printf("Enter new player age: ");
    scanf("%d", &players[id].age);
    printf("Enter new player position: ");
    scanf("%s", players[id].position);
    printf("Enter new team ID: ");
    scanf("%d", &players[id].team_id);
    printf("Player updated successfully.\n");
}