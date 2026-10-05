void updatePolice(PoliceForce *police, Player *player, CityMap *city) {
    printf("Updating police positions...\n");
    for (int i = 0; i < police->numCars; i++) {
        if (police->cars[i].position.x < player->position.x) {
            police->cars[i].position.x++;
        } else if (police->cars[i].position.x > player->position.x) {
            police->cars[i].position.x--;
        }
        if (police->cars[i].position.y < player->position.y) {
            police->cars[i].position.y++;
        } else if (police->cars[i].position.y > player->position.y) {
            police->cars[i].position.y--;
        }
    }
}