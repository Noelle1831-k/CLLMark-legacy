void free_game_data(GameData *data) {
    if (data) {
        free(data->games);
        free(data);
    }
}