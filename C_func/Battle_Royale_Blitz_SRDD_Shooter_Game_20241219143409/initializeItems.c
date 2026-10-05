void initializeItems(Item items[], int maxItems) {
    for (int i = 0; i < maxItems; i++) {
        items[i].x = rand() % 100;
        items[i].y = rand() % 100;
        items[i].type = rand() % 3; 
    }
    printf("%d items initialized.\n", maxItems);
}