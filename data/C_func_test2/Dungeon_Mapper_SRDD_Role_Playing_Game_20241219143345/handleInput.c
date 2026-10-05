void handleInput(SDL_Event event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        printf("Mouse button pressed at (%d, %d).\n", event.button.x, event.button.y);
        addRoom(event.button.x, event.button.y, 50, 50); 
    }
}