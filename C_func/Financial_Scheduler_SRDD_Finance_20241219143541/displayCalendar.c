void displayCalendar(Scheduler *scheduler) {
    printf("Financial Schedule for %s:\n", scheduler->user->name);
    for (int i = 0; i < scheduler->user->transactionCount; i++) {
        Transaction *transaction = scheduler->user->transactions[i];
        printf("%s: $%.2f (%s, %s)\n", transaction->name, transaction->amount, transaction->type, transaction->recurrence);
    }
}