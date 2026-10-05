void categorize_transaction(Transaction *transaction, const char *category) {
    strcpy(transaction->category, category);
}