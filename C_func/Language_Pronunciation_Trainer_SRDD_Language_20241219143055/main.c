int main() {
    int choice;
    printf("Welcome to the Language Pronunciation Trainer!\n");
    while (1) {
        print_instructions();
        printf("Choose an exercise:\n");
        printf("1. Tongue Twisters\n");
        printf("2. Word Stress Drills\n");
        printf("3. Intonation Practice\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                run_tongue_twister();
                break;
            case 2:
                run_word_stress_drill();
                break;
            case 3:
                run_intonation_practice();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}