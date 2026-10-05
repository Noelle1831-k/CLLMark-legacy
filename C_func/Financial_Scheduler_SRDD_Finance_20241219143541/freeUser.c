void freeUser(User *user) {
    for (int i = 0; i < user->transactionCount; i++) {
        freeTransaction(user->transactions[i]);
    }
    free(user->transactions);
    free(user->name);
    free(user);
}