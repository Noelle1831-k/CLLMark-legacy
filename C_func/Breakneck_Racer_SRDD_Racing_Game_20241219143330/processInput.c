int processInput(Car *car) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 0; 
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    car->acceleration += 0.1f;
                    break;
                case SDLK_DOWN:
                    car->acceleration -= 0.1f;
                    break;
                case SDLK_LEFT:
                    car->handling -= 0.1f;
                    break;
                case SDLK_RIGHT:
                    car->handling += 0.1f;
                    break;
                case SDLK_ESCAPE:
                    return 0; 
            }
        }
    }
    return 1;
}