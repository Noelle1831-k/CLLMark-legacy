Account *create_account(char *account_type, char *account_details) {
    Account *account = (Account *)malloc(sizeof(Account));
    strcpy(account->account_type, account_type);
    strcpy(account->account_details, account_details);
    printf("Account created: %s\n", account_type);
    return account;
}