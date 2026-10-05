void selectTrack(Game *game) {
    printf("Select a track:\n");
    game->track = createTrack(1000, 10, 5); 
    printf("Track selected!\n");
}