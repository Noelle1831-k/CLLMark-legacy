void renderGraphics(Player *player, Vehicle *vehicle, CityMap *city, PoliceForce *police) {
    printf("Rendering Game State...\n");
    printf("Player Position: (%d, %d)\n", player->position.x, player->position.y);
    printf("Vehicle Speed: %d, Agility: %d\n", vehicle->speed, vehicle->agility);
    printf("Police Count: %d\n", police->numCars);
}