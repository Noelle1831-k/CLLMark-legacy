void initializeApp() {
    printf("Initializing Dungeon Mapper...\n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        logError("SDL Initialization failed.");
        exit(EXIT_FAILURE);
    }
    window = SDL_CreateWindow("Dungeon Mapper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        logError("Window creation failed.");
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        logError("Renderer creation failed.");
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    initializeUI();
    loadTileset("default_tileset");
    createMap();
}