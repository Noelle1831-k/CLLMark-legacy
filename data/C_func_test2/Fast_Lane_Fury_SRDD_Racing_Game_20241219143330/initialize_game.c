void initialize_game() {
    printf("Initializing Fast Lane Fury...\n");
    srand(time(NULL)); 
    initialize_graphics();
    load_textures();
    load_track();
    create_player();
    printf("Game Initialized Successfully!\n");
}