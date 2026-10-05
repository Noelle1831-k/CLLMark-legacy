void removeCard(Collection *collection) {
    char name[50];
    printf("Enter card name to remove: ");
    scanf("%s", name);
    for (int i = 0; i < collection->size; i++) {
        if (strcmp(collection->cards[i]->name, name) == 0) {
            free(collection->cards[i]);
            for (int j = i; j < collection->size - 1; j++) {
                collection->cards[j] = collection->cards[j + 1];
            }
            collection->size--;
            printf("Card removed.\n");
            return;
        }
    }
    printf("Card not found.\n");
}