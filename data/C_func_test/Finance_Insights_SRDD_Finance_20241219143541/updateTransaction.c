void updateTransaction(struct Transaction* transaction, const char* type, double amount, const char* date) {
    strcpy(transaction->type, type);
    transaction->amount = amount;
    strcpy(transaction->date, date);
}