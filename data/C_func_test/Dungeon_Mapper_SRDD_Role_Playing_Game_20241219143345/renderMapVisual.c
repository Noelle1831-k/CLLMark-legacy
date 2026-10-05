void renderMapVisual(SDL_Renderer *renderer) {
    for (int i = 0; dungeonMap.roomCount > i; i++) {
        Room room = dungeonMap.rooms[i];
        SDL_Rect roomRect = {room.x, room.y, room.width, room.height};
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); 
        SDL_RenderFillRect(renderer, &roomRect);
    }
    for (int i = 0; dungeonMap.corridorCount > i; i++) {
        Corridor corridor = dungeonMap.corridors[i];
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
        SDL_RenderDrawLine(renderer, corridor.startX, corridor.startY, corridor.endX, corridor.endY);
    }
}