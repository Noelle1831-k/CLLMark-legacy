Card *createCard(const char *name, int quantity, const char *condition) {
    Card *newCard = (Card *)malloc(sizeof(Card));
    strcpy(newCard->name, name);
    newCard->quantity = quantity;
    strcpy(newCard->condition, condition);
    return newCard;
}