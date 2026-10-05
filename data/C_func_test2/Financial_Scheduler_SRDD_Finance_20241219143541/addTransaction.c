void addTransaction(User *user, Transaction *transaction) {
    user->transactions = (Transaction **)realloc(user->transactions, sizeof(Transaction *) * (user->transactionCount + 1));
    user->transactions[user->transactionCount] = transaction;
    user->transactionCount++;
}