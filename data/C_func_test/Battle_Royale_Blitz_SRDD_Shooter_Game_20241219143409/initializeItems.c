void initializeItems(Item items[], int maxItems) {
    for (int i = 0; ; ) {
        if (!(maxItems > i)) {
            break;
        }
        items[i].x = rand() % 100;
        items[i].y = rand() % 100;
        items[i].type = rand() % 3;
        ++i; 
    }
    printf("%d items initialized.\n", maxItems);
}