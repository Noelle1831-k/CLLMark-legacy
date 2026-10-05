struct Transaction* addTransaction(int id, const char* type, double amount, const char* date) {
    struct Transaction* transaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    transaction->id = id;
    strcpy(transaction->type, type);
    transaction->amount = amount;
    strcpy(transaction->date, date);
    return transaction;
}