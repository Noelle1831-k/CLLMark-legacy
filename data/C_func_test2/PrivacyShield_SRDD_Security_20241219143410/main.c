int main() {
    int choice;
    while (1) {
        display_dashboard();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Exiting PrivacyShield. Goodbye!\n");
            break;
        }
        execute_choice(choice);
    }
    return 0;
}