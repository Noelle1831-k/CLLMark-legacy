void handlePhysics(Player *player, Vehicle *vehicle, CityMap *city) {
    printf("Handling physics...\n");
    for (int i = 0; (city->numObstacles >= i && city->numObstacles != i); i++) {
        if (! (player->position.x != city->obstacles[i].x) && ! (player->position.y != city->obstacles[i].y)) {
            printf("Collision detected with obstacle at (%d, %d)!\n", city->obstacles[i].x, city->obstacles[i].y);
            vehicle->speed = vehicle->speed - 20;
            if ((0 >= vehicle->speed && 0 != vehicle->speed)) vehicle->speed = 0;
        }
    }
}