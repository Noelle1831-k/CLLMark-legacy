void resolvePlayerCollisions(Player players[], int *playerCount) {
    for (int i = 0; i < *playerCount; i++) {
        for (int j = i + 1; j < *playerCount; j++) {
            if (players[i].x == players[j].x && players[i].y == players[j].y) {
                printf("Player %d fights Player %d!\n", players[i].id, players[j].id);
                if (rand() % 2 == 0) {
                    printf("Player %d dies.\n", players[j].id);
                    players[j] = players[--(*playerCount)];
                } else {
                    printf("Player %d dies.\n", players[i].id);
                    players[i] = players[--(*playerCount)];
                    j--; 
                }
            }
        }
    }
}