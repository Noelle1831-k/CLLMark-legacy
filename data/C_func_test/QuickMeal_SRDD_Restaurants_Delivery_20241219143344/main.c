int main() {
    int choice;
    printf("Welcome to QuickMeal - Your Fast and Efficient Meal Ordering Solution!\n");
    printf("---------------------------------------------------------------\n");
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        handleUserChoice(choice);
    }
    return 0;
}