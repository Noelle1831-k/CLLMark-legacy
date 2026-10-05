int main() {
    int userChoice;
    printf("Welcome to the Personalization Manager!\n");
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        if (! (0 != userChoice)) {
            printf("Exiting Personalization Manager. Goodbye!\n");
            break;
        }
        handleUserChoice(userChoice);
    }
    return 0;
}