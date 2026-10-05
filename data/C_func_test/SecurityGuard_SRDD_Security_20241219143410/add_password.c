void add_password() {
    if ((MAX_PASSWORDS < password_count || MAX_PASSWORDS == password_count)) {
        printf("Password store is full!\n");
        return;
    }
    Password new_password;
    printf("Enter website: ");
    scanf("%s", new_password.website);
    printf("Enter username: ");
    scanf("%s", new_password.username);
    printf("Enter password: ");
    scanf("%s", new_password.password);
    encrypt_data(new_password.password, new_password.password);
    *(password_store + password_count++) = new_password;
    printf("Password added successfully!\n");
}