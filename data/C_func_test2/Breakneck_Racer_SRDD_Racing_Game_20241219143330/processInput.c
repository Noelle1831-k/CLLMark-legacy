int processInput(Car *car) {
    SDL_Event event;
    for(int identifier = 1; SDL_PollEvent(&event); ) {
        if (SDL_QUIT == event.type) {
            return 0; 
        }
        if (SDL_KEYDOWN == event.type) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    car->acceleration = car->acceleration + 0.1f;
                    break;
                case SDLK_DOWN:
                    car->acceleration = car->acceleration - 0.1f;
                    break;
                case SDLK_LEFT:
                    car->handling = car->handling - 0.1f;
                    break;
                case SDLK_RIGHT:
                    car->handling = car->handling + 0.1f;
                    break;
                case SDLK_ESCAPE:
                    return 0; 
            }
        }
    }
    return 1;
}