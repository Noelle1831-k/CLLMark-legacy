void checkCollisions() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (0 < enemies[i].health && enemies[i].x == player.x && player.y == enemies[i].y) {
            player.health = player.health - enemies[i].damage;
            enemies[i].health = 0;  
            printf("Collision! Player hit by %s. Player Health: %d\n", enemies[i].type, player.health);
            if (player.health <= 0) {
                printf("Game Over! Player has been defeated.\n");
                exit(0);
            }
        }
    }
}