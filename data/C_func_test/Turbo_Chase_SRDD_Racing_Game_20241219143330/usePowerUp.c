void usePowerUp(Player *player, Vehicle *vehicle) {
    printf("Using power-up!\n");
    vehicle->speed = vehicle->speed + 50;
    player->hasPowerUp = 0; 
}