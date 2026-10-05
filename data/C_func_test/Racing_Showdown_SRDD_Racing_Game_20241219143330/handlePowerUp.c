void handlePowerUp(Game *game, Vehicle *vehicle, int position) {
    for (int i = 0; i < MAX_POWERUPS; i++) {
        if (game->powerUps[i].position == position) {
            switch (game->powerUps[i].type) {
                case 0:
                    printf("%s activated a Boost!\n", vehicle->name);
                    vehicle->speed += 20;
                    break;
                case 1:
                    printf("%s gained a Shield!\n", vehicle->name);
                    vehicle->handling += 5;
                    break;
                case 2:
                    printf("%s hit a Slowdown!\n", vehicle->name);
                    vehicle->speed -= 15;
                    break;
            }
        }
    }
}