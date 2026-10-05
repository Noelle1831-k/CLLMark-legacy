void freeTransaction(Transaction *transaction) {
    free(transaction->name);
    free(transaction->type);
    free(transaction->recurrence);
    free(transaction);
}