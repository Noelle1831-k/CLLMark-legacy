void manage_passwords() {
    int choice;
    while (1) {
        printf("\n==== Password Manager ====\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit Password Manager\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            add_password();  
        } else if (choice == 2) {
            view_passwords();  
        } else if (choice == 3) {
            break;  
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}