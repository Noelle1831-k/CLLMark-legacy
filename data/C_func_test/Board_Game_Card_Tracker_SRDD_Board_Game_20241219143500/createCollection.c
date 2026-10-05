Collection *createCollection() {
    Collection *collection = (Collection *)malloc(sizeof(Collection));
    collection->size = 0;
    collection->capacity = 10;
    collection->cards = (Card **)malloc(collection->capacity * sizeof(Card *));
    return collection;
}