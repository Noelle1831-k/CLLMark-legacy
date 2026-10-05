int main() {
    int choice;
    char language[20];
    int difficulty;
    srand(time(NULL));
    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid option.\n");
            while(getchar() != '\n');  
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter language (e.g., English, Spanish): ");
                if (scanf("%s", language) != 1) {
                    printf("Invalid input. Please enter a valid language.\n");
                    while(getchar() != '\n');  
                    continue;
                }
                printf("Enter difficulty level (1 - Easy, 2 - Medium, 3 - Hard): ");
                if (scanf("%d", &difficulty) != 1 || difficulty < 1 || difficulty > 3) {
                    printf("Invalid input. Please enter a valid difficulty level between 1 and 3.\n");
                    while(getchar() != '\n');  
                    continue;
                }
                start_quiz(language, difficulty);
                break;
            case 2:
                display_progress();
                break;
            case 3:
                printf("Thank you for using the Language Spelling Bee. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}