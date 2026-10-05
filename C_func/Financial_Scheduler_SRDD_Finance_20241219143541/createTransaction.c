Transaction *createTransaction(const char *name, double amount, const char *type, const char *recurrence) {
    Transaction *transaction = (Transaction *)malloc(sizeof(Transaction));
    transaction->name = strdup(name);
    transaction->amount = amount;
    transaction->type = strdup(type);
    transaction->recurrence = strdup(recurrence);
    return transaction;
}