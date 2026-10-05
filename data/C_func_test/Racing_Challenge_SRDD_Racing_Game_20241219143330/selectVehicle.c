void selectVehicle(Game *game) {
    printf("Select a vehicle:\n");
    game->player->vehicle = createVehicle("Speedster", 200, 10, 8); 
    printf("Vehicle selected: %s\n", game->player->vehicle->name);
}