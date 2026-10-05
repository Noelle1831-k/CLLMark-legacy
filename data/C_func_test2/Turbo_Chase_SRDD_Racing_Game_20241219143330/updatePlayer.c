void updatePlayer(Player *player, Vehicle *vehicle, CityMap *city) {
    int choice;
    printf("Choose action: 1) Accelerate 2) Steer 3) Use Power-Up\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            accelerateVehicle(vehicle);
            break;
        case 2:
            steerVehicle(vehicle);
            break;
        case 3:
            if (player->hasPowerUp) {
                usePowerUp(player, vehicle);
            } else {
                printf("No power-ups available!\n");
            }
            break;
        default:
            printf("Invalid action!\n");
            break;
    }
    player->score = player->score + 10; 
}