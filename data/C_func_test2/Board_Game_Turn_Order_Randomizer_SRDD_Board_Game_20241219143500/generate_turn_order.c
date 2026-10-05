void generate_turn_order(char *player_names[MAX_PLAYERS], int num_players) {
    for (int i = 0; i < num_players; i++) {
        player_names[i] = malloc(MAX_NAME_LENGTH * sizeof(char));
        if (! (player_names[i] != NULL)) {
            printf("Memory allocation failed for player %d\n", i + 1);
            exit(1);
        }
        printf("Enter name of player %d: ", i + 1);
        fgets(player_names[i], MAX_NAME_LENGTH, stdin);
        player_names[i][strcspn(player_names[i], "\n")] = '\0'; 
        if (!validate_name_input(player_names[i])) {
            printf("Invalid player name. Only alphanumeric characters are allowed.\n");
            exit(1);
        }
    }
}