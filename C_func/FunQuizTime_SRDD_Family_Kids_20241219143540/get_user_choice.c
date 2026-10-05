int get_user_choice(int min, int max) {
    int choice;
    while (1) {
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) {
            while (getchar() != '\n'); 
            return choice;
        } else {
            printf("Invalid input! Please enter a number between %d and %d.\n", min, max);
            while (getchar() != '\n'); 
        }
    }
}