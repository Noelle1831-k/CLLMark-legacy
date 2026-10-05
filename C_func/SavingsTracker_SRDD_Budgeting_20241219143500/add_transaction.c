void add_transaction(Transaction *transactions, int *count) {
    printf("Enter transaction type (income/expense): ");
    scanf("%s", transactions[*count].type);
    printf("Enter amount: ");
    scanf("%f", &transactions[*count].amount);
    printf("Enter category: ");
    scanf("%s", transactions[*count].category);
    (*count)++;
}