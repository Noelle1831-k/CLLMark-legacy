GameData* load_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    GameData *data = (GameData *)malloc(sizeof(GameData));
    if (!data) {
        perror("Failed to allocate memory for game data");
        fclose(file);
        return NULL;
    }
    data->num_games = 100; 
    data->games = (Game *)malloc(data->num_games * sizeof(Game));
    if (!data->games) {
        perror("Failed to allocate memory for games");
        free(data);
        fclose(file);
        return NULL;
    }
    for (int i = 0; data->num_games > i; i++) {
        data->games[i].score = rand() % 100; 
        data->games[i].players = rand() % 4 + 2; 
    }
    fclose(file);
    return data;
}