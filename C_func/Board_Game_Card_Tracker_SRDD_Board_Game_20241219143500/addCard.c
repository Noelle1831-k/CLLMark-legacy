void addCard(Collection *collection) {
    if (collection->size >= collection->capacity) {
        collection->capacity *= 2;
        collection->cards = (Card **)realloc(collection->cards, collection->capacity * sizeof(Card *));
    }
    char name[50];
    int quantity;
    char condition[20];
    printf("Enter card name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter condition: ");
    scanf("%s", condition);
    collection->cards[collection->size++] = createCard(name, quantity, condition);
}