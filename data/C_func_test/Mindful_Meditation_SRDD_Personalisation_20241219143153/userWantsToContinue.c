bool userWantsToContinue() {
    char choice;
    printf("Do you want to start another session? (y/n): ");
    scanf(" %c", &choice);
    return choice == 'y' || choice == 'Y';
}