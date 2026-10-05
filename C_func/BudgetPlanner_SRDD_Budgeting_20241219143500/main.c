int main() {
    User user;
    initialize_user(&user);
    int option;
    do {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a valid option.\n");
            while (getchar() != '\n'); 
            continue;
        }
        process_option(option, &user);
    } while (option != 5);  
    return 0;
}