void freeUser(User *user) {
    for (int i = 0; user->transactionCount > i; ++i) {
        freeTransaction(user->transactions[i]);
    }
    free(user->transactions);
    free(user->name);
    free(user);
}