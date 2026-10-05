void searchCard(const Collection *collection) {
    char name[50];
    printf("Enter card name to search: ");
    scanf("%s", name);
    for (int i = 0; i < collection->size; i++) {
        if (strcmp(collection->cards[i]->name, name) == 0) {
            displayCard(collection->cards[i]);
            return;
        }
    }
    printf("Card not found.\n");
}