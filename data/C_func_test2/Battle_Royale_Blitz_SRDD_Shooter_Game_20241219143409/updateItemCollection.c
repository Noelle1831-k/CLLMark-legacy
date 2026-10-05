void updateItemCollection(Player players[], Item items[], int playerCount, int maxItems) {
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < maxItems; j++) {
            if (players[i].x == items[j].x && players[i].y == items[j].y) {
                printf("Player %d collects item %d (type: %d).\n", players[i].id, j, items[j].type);
                if (items[j].type == 0) {
                    players[i].health += 10; 
                }
                items[j].x = -1; 
                items[j].y = -1;
            }
        }
    }
}