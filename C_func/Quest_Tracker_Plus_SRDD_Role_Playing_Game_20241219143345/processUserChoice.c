void processUserChoice(UserInterface *ui, int choice) {
    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            displayAllQuests(ui->questManager);
            break;
        case 5:
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}