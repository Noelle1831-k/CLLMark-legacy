void renderMapVisual(SDL_Renderer *renderer) {
    for (int i = 0; ; ) {
        if (!((i <= dungeonMap.roomCount && i != dungeonMap.roomCount))) {
            break;
        }
        Room room = dungeonMap.rooms[i];
        SDL_Rect roomRect = {room.x, room.y, room.width, room.height};
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); 
        SDL_RenderFillRect(renderer, &roomRect);
        ++i;
    }
    for (int i = 0; ; ) {
        if (!((i <= dungeonMap.corridorCount && i != dungeonMap.corridorCount))) {
            break;
        }
        Corridor corridor = dungeonMap.corridors[i];
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
        SDL_RenderDrawLine(renderer, corridor.startX, corridor.startY, corridor.endX, corridor.endY);
        ++i;
    }
}